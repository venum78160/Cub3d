/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:39:52 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/25 00:48:19 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_path_len(char *line, int start)
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

char	*get_path(char *line, int start)
{
	char	*res;
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

void	handle_ns(t_info *info, int type, char *path)
{
	int	x;
	int	y;

	if (type == 0)
	{
		info->valid.n = 1;
		info->text.text_n = ft_calloc(sizeof(t_data), 1);
		info->text.text_n->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_n->addr = mlx_get_data_addr(info->text.text_n->img,
				&info->text.text_n->bppixel,
				&info->text.text_n->line_length,
				&info->text.text_n->endian);
	}
	if (type == 1)
	{
		info->valid.s = 1;
		info->text.text_s = ft_calloc(sizeof(t_data), 1);
		info->text.text_s->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_s->addr = mlx_get_data_addr(info->text.text_s->img,
				&info->text.text_s->bppixel,
				&info->text.text_s->line_length,
				&info->text.text_s->endian);
	}
}

void	handle_ew(t_info *info, int type, char *path)
{
	int	x;
	int	y;

	if (type == 2)
	{
		info->valid.w = 1;
		info->text.text_w = ft_calloc(sizeof(t_data), 1);
		info->text.text_w->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_w->addr = mlx_get_data_addr(info->text.text_w->img,
				&info->text.text_w->bppixel,
				&info->text.text_w->line_length,
				&info->text.text_w->endian);
	}
	if (type == 3)
	{
		info->valid.e = 1;
		info->text.text_e = ft_calloc(sizeof(t_data), 1);
		info->text.text_e->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_e->addr = mlx_get_data_addr(info->text.text_e->img,
				&info->text.text_e->bppixel,
				&info->text.text_e->line_length,
				&info->text.text_e->endian);
	}
}

int	handle_path(char *line, int type, t_info *info, char *id)
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
	handle_ns(info, type, path);
	handle_ew(info, type, path);
	free(path);
	return (1);
}
