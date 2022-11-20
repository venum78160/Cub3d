/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_help.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 19:07:47 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/20 21:21:58 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		dst = data->addr + (y * data->line_length + x * (data->bppixel / 8));
		*(int *) dst = color;
	}
}

void	get_color(t_data *data, int x, int y)
{

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		data->color = data->addr + (y * data->line_length - x * (data->bppixel / 8));
	}
}

void	backgroud(t_info *i)
{
	int x;
	int y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			if( y <= (HEIGHT / 2))
				my_mlx_pixel_put(&i->st_img, x, y, i->ceiling_c);
			else
				my_mlx_pixel_put(&i->st_img, x, y, i->floor_c);
		}
	}
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->st_img.img, 0, 0);
}