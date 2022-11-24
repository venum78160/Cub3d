/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:39:52 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:06:11 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
		info->valid.N = 1;
		info->text.text_N = ft_calloc(sizeof(t_data), 1);
		info->text.text_N->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_N->addr = mlx_get_data_addr(info->text.text_N->img,
				&info->text.text_N->bppixel,
				&info->text.text_N->line_length,
				&info->text.text_N->endian);
	}
	if (type == 1)
	{
		info->valid.S = 1;
		info->text.text_S = ft_calloc(sizeof(t_data), 1);
		info->text.text_S->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_S->addr = mlx_get_data_addr(info->text.text_S->img,
				&info->text.text_S->bppixel,
				&info->text.text_S->line_length,
				&info->text.text_S->endian);
	}
}

void	handle_ew(t_info *info, int type, char *path)
{
	int	x;
	int	y;

	if (type == 2)
	{
		info->valid.W = 1;
		info->text.text_W = ft_calloc(sizeof(t_data), 1);
		info->text.text_W->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_W->addr = mlx_get_data_addr(info->text.text_W->img,
				&info->text.text_W->bppixel,
				&info->text.text_W->line_length,
				&info->text.text_W->endian);
	}
	if (type == 3)
	{
		info->valid.E = 1;
		info->text.text_E = ft_calloc(sizeof(t_data), 1);
		info->text.text_E->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_E->addr = mlx_get_data_addr(info->text.text_E->img,
				&info->text.text_E->bppixel,
				&info->text.text_E->line_length,
				&info->text.text_E->endian);
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
