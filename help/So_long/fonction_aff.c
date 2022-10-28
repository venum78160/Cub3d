/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_aff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:41:04 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/11 16:56:03 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ml_rect(t_info info, t_rect rect, int color)
{
	int	ybis;

	rect.x--;
	while (++rect.x <= rect.m_x)
	{
		ybis = rect.y - 1;
		while (++ybis < rect.m_y)
			my_mlx_pixel_put(&info.st_img, rect.x, ybis, color);
	}
	return ;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 700 && y >= 0 && y < 700)
	{
		dst = data->addr + (y * data->line_length + x * (data->bppixel / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_mlx_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bppixel / 8));
	return (*(unsigned int *) dst);
}

int	ft_quit(t_info *i)
{
	mlx_destroy_window(i->mlx, i->mlx_win);
	ft_del_maps (i, "exit");
	return (EXIT_SUCCESS);
}
