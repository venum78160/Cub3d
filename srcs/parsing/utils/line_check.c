/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:47:07 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:17:33 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	map_char_check(char c)
{
	if (c == ' ')
		return (1);
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'P')
		return (1);
	if (c == 'O')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

int	line_map_checker(char *line, t_list **head, t_info *info)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!map_char_check(line[i]))
		{
			free(line);
			free_texture(info);
			ft_lstclear(head, clear_lst);
			ft_error("Error:\nwrong character in map.\n", 0);
		}
		i++;
	}
	return (1);
}

int	wall_line_checker_tb(char *line, char **map, t_info *info)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\n')
		{
			free_map(map);
			free_texture(info);
			ft_error("Error:\nmap has to be closed by wall.\n", 0);
		}
		i++;
	}
	return (1);
}
