/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:15:59 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/30 17:12:39 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_info *i, int x)
{
	i->pla.camerax = 2 * x / (double)(WIDTH)-1;
	i->pla.raydirx = i->pla.dirx + i->pla.plane_x * i->pla.camerax;
	i->pla.raydiry = i->pla.diry + i->pla.plane_y * i->pla.camerax;
	i->pla.mapx = (int)i->pla.pl_x;
	i->pla.mapy = (int)i->pla.pl_y;
	if (!i->pla.raydirx)
		i->pla.delta_x = INFINITY;
	else
		i->pla.delta_x = fabs(1 / i->pla.raydirx);
	if (!i->pla.raydiry)
		i->pla.delta_y = INFINITY;
	else
		i->pla.delta_y = fabs(1 / i->pla.raydiry);
	i->pla.hit = 0;
	i->pla.hit_door = 0;
	step(i);
	dda(i);
}

void	step(t_info *i)
{
	if (i->pla.raydirx < 0)
	{
		i->pla.step_x = -1;
		i->pla.side_disx = (i->pla.pl_x - i->pla.mapx) * i->pla.delta_x;
	}
	else
	{
		i->pla.step_x = 1;
		i->pla.side_disx = (i->pla.mapx + 1.0 - i->pla.pl_x) * i->pla.delta_x;
	}
	if (i->pla.raydiry < 0)
	{
		i->pla.step_y = -1;
		i->pla.side_disy = (i->pla.pl_y - i->pla.mapy) * i->pla.delta_y;
	}
	else
	{
		i->pla.step_y = 1;
		i->pla.side_disy = (i->pla.mapy + 1.0 - i->pla.pl_y) * i->pla.delta_y;
	}
}

void	dda(t_info *i)
{
	while (i->pla.hit == 0 && i->pla.hit_door == 0)
	{
		if (i->pla.side_disx < i->pla.side_disy)
		{
			i->pla.side_disx += i->pla.delta_x;
			i->pla.mapx += i->pla.step_x;
			i->pla.side = 0;
		}
		else
		{
			i->pla.side_disy += i->pla.delta_y;
			i->pla.mapy += i->pla.step_y;
			i->pla.side = 1;
		}
		if (i->map[i->pla.mapx][i->pla.mapy] == '1')
			i->pla.hit = 1;
		if (i->map[i->pla.mapx][i->pla.mapy] == 'P')
			i->pla.hit_door = 1;
	}
}
