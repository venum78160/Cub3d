/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:39:52 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:27:47 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void    handle_NS(t_info *info, int type, char* path)
{
	int x;
	int y;

	if (type == 0)
	{
		info->valid.N = 1;
		info->text.text_n = ft_calloc(sizeof(t_data), 1);
		info->text.text_n->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_n->addr = mlx_get_data_addr(info->text.text_n->img, &info->text.text_n->bppixel,
				&info->text.text_n->line_length, &info->text.text_n->endian);
	}
	if (type == 1)
	{
		info->valid.S = 1;
		info->text.text_s = ft_calloc(sizeof(t_data), 1);
		info->text.text_s->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_s->addr = mlx_get_data_addr(info->text.text_s->img, &info->text.text_s->bppixel,
				&info->text.text_s->line_length, &info->text.text_s->endian);
	}
}

void    handle_EW(t_info *info, int type, char* path)
{
	int x;
	int y;

	if (type == 2)
	{
		info->valid.W = 1;
		info->text.text_w = ft_calloc(sizeof(t_data), 1);
		info->text.text_w->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_w->addr = mlx_get_data_addr(info->text.text_w->img, &info->text.text_w->bppixel,
				&info->text.text_w->line_length, &info->text.text_w->endian);
	}
	if (type == 3)
	{
		info->valid.E = 1;
		info->text.text_e = ft_calloc(sizeof(t_data), 1);
		info->text.text_e->img = mlx_xpm_file_to_image(info->mlx , path, &x, &y);
		info->text.text_e->addr = mlx_get_data_addr(info->text.text_e->img, &info->text.text_e->bppixel,
				&info->text.text_e->line_length, &info->text.text_e->endian);
	}
}

int handle_path(char *line, int type, t_info *info, char *id)
{
	char	*path;

	path = get_path(line, 2);
	if (!check_extension(path, ".xpm"))
	{
		free(path);
		free(id);
		ft_error("Error:\nBad path, file type is wrong.\n", 0);
	}
	close(ft_open(path));
	handle_NS(info, type, path);
	handle_EW(info, type, path);
	handle_bonus(info, type, path);
	free(path);
	return (1);
}
