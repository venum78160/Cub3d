/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:23:52 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/22 15:05:18 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int free_texture(t_info *info)
{
	free(info->text.text_S);
	free(info->text.text_N);
	free(info->text.text_W);
	free(info->text.text_E);
	return (0);
}

void	clear_lst(void *el)
{
	(void)el;
}

int check_extension(char* src, char *type)
{
	char *extension = get_extension(src);
	if (ft_strcmp(extension, type))
	{
		free(extension);
		return (0);
	}
	free(extension);
	return (1);
}

char    *get_id(char *line)
{
	char    *id;
	int     i;

	id = ft_calloc(3, 1);
	i = 0;
	while (i < 2)
	{
		id[i] = line[i];
		i++;
	}
	id[i] = '\0';
	return (id);
}

int get_path_len(char *line, int start)
{
	int		i;

	i = 0;
	while (line[start] == ' ' || line[start] == '	')
		start++;
	while (line[start] && line[start] != ' '
			&& line[start] != '	' && line[start] != '\n')
	{
		i++;
		start++;
	}
	return (i);
}

char *get_path(char *line, int start)
{
	char    *res;
	int		i;

	i = 0;
	res = ft_calloc(get_path_len(line, start) + 1, 1);
	while (line[start] == ' ' || line[start] == '	')
		start++;
	while (line[start] && line[start] != ' '
			&& line[start] != '	' && line[start] != '\n')
	{
		res[i] = line[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int handle_path(char *line, int type, t_info *info, char *id)
{
	char	*path;
	int		x;
	int		y;

	path = get_path(line, 2);
	if (!check_extension(path, ".xpm"))
	{
		free(id);
		ft_error("Error:\nBad path, file type is wrong.\n", 0);
	}
	close(ft_open(path));
	if (type == 0)
	{
		info->text.text_N = ft_calloc(sizeof(t_data), 1);
		info->text.text_N->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_N->addr = mlx_get_data_addr(info->text.text_N->img, &info->text.text_N->bppixel,
			&info->text.text_N->line_length, &info->text.text_N->endian);
	}
	if (type == 1)
	{
		info->text.text_S = ft_calloc(sizeof(t_data), 1);
		info->text.text_S->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_S->addr = mlx_get_data_addr(info->text.text_S->img, &info->text.text_S->bppixel,
			&info->text.text_S->line_length, &info->text.text_S->endian);
	}
	if (type == 2)
	{
		info->text.text_W = ft_calloc(sizeof(t_data), 1);
		info->text.text_W->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_W->addr = mlx_get_data_addr(info->text.text_W->img, &info->text.text_W->bppixel,
			&info->text.text_W->line_length, &info->text.text_W->endian);
	}
	if (type == 3)
	{
		info->text.text_E = ft_calloc(sizeof(t_data), 1);
		info->text.text_E->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_E->addr = mlx_get_data_addr(info->text.text_E->img, &info->text.text_E->bppixel,
			&info->text.text_E->line_length, &info->text.text_E->endian);
	}
	free(path);
	return (1);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int check_rgb(int n)
{
	if (n <= 255 && n >= 0)
		return (1);
	return (0);
}

int colors_to_trgb(char **colors, char *id)
{
	int	i;
	int	r;
	int	g;
	int	b;

    i = 0;
	while (colors[i])
		i++;
	if (i < 3)
	{
		free(id);
		ft_error("Error:\n bad colors\n", 0);
	}
	r = ft_atoi(colors[0]);
	g =	ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!check_rgb(r) || !check_rgb(g) || !check_rgb(b))
	{
		free(id);
		ft_error("Error:\nrgb must be between 0-255.\n", 0);
	}
	return (create_trgb(1, r, g, b));
}

int handle_color(char *line, int type, t_info *info, char* id)
{
	char	**colors;
	int		trgb;
	int		i;

	i = 0;
	colors = ft_split(++line, ',');
	trgb = colors_to_trgb(colors, id);
	if (type == 0)
		info->floor_c = trgb;
	if (type == 1)
		info->ceiling_c = trgb;
	while (colors[i])
		free(colors[i++]);
	free(colors);
	return (1);
}

int check_for_id(char *line, t_info *info)
{
	char    *id;

	id = get_id(line);
	if (!ft_strcmp(id, "NO"))
		return (handle_path(line, 0, info, id));
	if (!ft_strcmp(id, "SO"))
		return (handle_path(line, 1, info, id));
	if (!ft_strcmp(id, "WE"))
		return (handle_path(line, 2, info, id));
	if (!ft_strcmp(id, "EA"))
		return (handle_path(line, 3, info, id));
	if (line[0] && line[0] == 'F')
		return (handle_color(line, 0, info, id));
	if (line[0] && line[0] == 'C')
		return (handle_color(line, 1, info, id));
	free(id);
	return (0);
}

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
	return (1);
}

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

int	char_checker(char c, int j)
{
	if (j < 0 || c == '\0')
		return (1);
	if (c == '1' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	spot_checker(char **map, int i, int j)
{
	if (!char_checker(map[i][j + 1], j + 1)) //after
		return (0);
	if (!char_checker(map[i][j - 1], j - 1)) //before
		return (0);
	if (!char_checker(map[i + 1][j], j)) //top
		return (0);
	if (!char_checker(map[i + 1][j + 1], j + 1)) //top-right
		return (0);
	if (!char_checker(map[i + 1][j - 1], j - 1)) //top-left
		return (0);
	if (!char_checker(map[i - 1][j], j)) //bottom
		return (0);
	if (!char_checker(map[i - 1][j + 1], j + 1)) //bottom-right
		return (0);
	if (!char_checker(map[i - 1][j - 1], j - 1)) //bottom-left
		return (0);
	return (1);
}

int	wall_line_checker(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == ' ' || map[i][j] == '\n' || map[i][j] == '\0')
		{
			if (!spot_checker(map, i, j))
				return (0);
		}
		else if (!j)
		{
			if (map[i][j] != '1')
				return (0);
		}
		j++;
	}
	return (1);
}

void	wall_check(char **map, t_info *info)
{
	int	i;

	i = 0;
	while(map[i])
	{
		if (!i)
			wall_line_checker_tb(map[i], map, info);
		else if (!map[i + 1])
			wall_line_checker_tb(map[i], map, info);
		else
		{
			if (!wall_line_checker(map, i))
			{
				free(map);
				free_texture(info);
				ft_error("Error:\nmap must be closed.\n", 0);
			}
		}

		i++;
	}
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

int try_set_spawn_point(char c, t_info *infos)
{
    if (c == 'N')
    {
        infos->pla.dirX = -1;
        infos->pla.dirY = 0;
        infos->pla.planeX = 0;
        infos->pla.planeY = FOVY;
        return (1);
    }
    if (c == 'S')
    {
        infos->pla.dirX = 1;
        infos->pla.dirY = 0;
        infos->pla.planeX = 0;
        infos->pla.planeY = -1 * FOVY;
        return (1);
    }
    if (c == 'E')
    {
        infos->pla.dirX = 0;
        infos->pla.dirY = 1;
        infos->pla.planeX = FOVY;
        infos->pla.planeY = 0;
        return (1);
    }
    if (c == 'W')
    {
        infos->pla.dirX = 0;
        infos->pla.dirY = -1;
        infos->pla.planeX = -1 * FOVY;
        infos->pla.planeY = 0;
        return (1);
    }
    return (0);
}

int	set_spawn(char **map, t_info *infos)
{
	int	i;
	int	j;
	int	spawn_amount;

	i = 0;
	spawn_amount = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (try_set_spawn_point(map[i][j], infos))
			{
				spawn_amount++;
				if (spawn_amount > 1)
				{
					free_map(map);
					free_texture(infos);
					ft_error("Error:\nmore than 1 spawn.\n", 0);
				}
				infos->pla.pl_y = (double)j + 0.5;
				infos->pla.pl_x = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	*remove_newline(char *line)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc(ft_strlen(line), 1);
	while(line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	free(line);
	return (res);
}

int	map_parsing(char *line, int fd, t_info *i)
{
	char	**map;
	t_list	**head;
	
	head = ft_calloc(sizeof(t_list), 1);
	while(line)
	{
		line_map_checker(line, head, i);
		ft_lstadd_back(head, ft_lstnew(remove_newline(line)));
		line = get_next_line(fd);
	}
	map = lst_to_map(head);
	wall_check(map, i);
	set_spawn(map, i);
	i->map = map;
	return (1);
}

void parsing_v2(t_info *i, char *src)
{
	int     fd;
	char    *line;
	
	if (!check_extension(src, ".cub"))
		ft_error("Error:\nBad file type.", 0);
	fd = ft_open(src);
	line = get_next_line(fd);
	while(line)
	{
		if (!check_for_id(line, i) && !is_empty_line(line))
			map_parsing(line, fd, i);
		line = get_next_line(fd);
	}
  	i->pla.time = 0; //time of current frame
  	i->pla.oldtime = 0; //time of previous frame
}