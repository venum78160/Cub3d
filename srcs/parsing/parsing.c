/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:23:52 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/30 16:46:57 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '	' && line[i] != '\n')
			return (0);
		i++;
	}
	free(line);
	return (1);
}

char	**lst_to_map(t_list **head)
{
	t_list	*lst;
	char	**map;
	int		i;

	lst = *head;
	map = ft_calloc(sizeof(char *), ft_lstsize(lst) + 1);
	i = 0;
	while (lst)
	{
		map[i] = lst->content;
		i++;
		lst = lst->next;
	}
	map[i] = 0;
	ft_lstclear(head, clear_lst);
	return (map);
}

int	map_parsing(char *line, int fd, t_info *i)
{
	char	**map;
	t_list	**head;

	i->valid.map = 1;
	head = ft_calloc(sizeof(t_list), 1);
	while (line)
	{
		if (!is_empty_line(line))
		{
			line_map_checker(line, head, i);
			ft_lstadd_back(head, ft_lstnew(line));
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	map = lst_to_map(head);
	free(head);
	wall_check(map, i);
	set_spawn(map, i);
	i->map = map;
	return (1);
}

void	parsing_v2(t_info *i, char *src)
{
	int		fd;
	char	*line;

	init_valid(i);
	if (!check_extension(src, ".cub"))
		ft_error("Error:\nBad file type.", 0);
	(void)i;
	fd = ft_open(src);
	line = get_next_line(fd);
	while (line)
	{
		if (!check_for_id(line, i) && !is_empty_line(line))
			map_parsing(line, fd, i);
		line = get_next_line(fd);
	}
	close(fd);
	if (!check_valid(i))
	{
		free_map(i->map);
		free_texture(i);
		ft_error("Error:\nMissing arguments in .cub\n", 0);
	}
}
