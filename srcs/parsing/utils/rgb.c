/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:40:28 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:17:40 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	check_rgb(int n)
{
	if (n <= 255 && n >= 0)
		return (1);
	return (0);
}

int	colors_to_trgb(char **colors, char *id)
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
		free(colors);
		free(id);
		ft_error("Error:\n bad colors\n", 0);
	}
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	if (!check_rgb(r) || !check_rgb(g) || !check_rgb(b))
	{
		free(colors);
		free(id);
		ft_error("Error:\nrgb must be between 0-255.\n", 0);
	}
	return (create_trgb(1, r, g, b));
}

int	handle_color(char *line, int type, t_info *info, char *id)
{
	char	**colors;
	int		trgb;

	colors = ft_split(++line, ',');
	trgb = colors_to_trgb(colors, id);
	if (type == 0)
	{
		info->valid.F = 1;
		info->floor_c = trgb;
	}
	if (type == 1)
	{
		info->valid.C = 1;
		info->ceiling_c = trgb;
	}
	free_colors(colors);
	return (1);
}
