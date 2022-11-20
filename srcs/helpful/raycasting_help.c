/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:07:47 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/20 16:05:55 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bppixel / 8));
		*(unsigned int *) dst = color;
	}
}

void	get_color(t_data *data, int x, int y)
{

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		data->color = data->addr + (y * data->line_length - x * (data->bppixel / 8));
	}
}