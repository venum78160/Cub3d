/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:19:34 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:56 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keyevent(int keyword, t_info *i)
{
	if (keyword == UP)
		mv_up(i);
	if (keyword == DOWN)
		mv_down(i);
	if (keyword == LEFT)
		mv_left(i);
	if (keyword == RIGHT)
		mv_right(i);
	if (keyword == SPACE)
		action_door_around((int)i->pla.pl_x, (int)i->pla.pl_y, i);
	if (keyword == ARROW_R)
		right_turn(i);
	if (keyword == ARROW_L)
		left_turn(i);
	if (keyword == ESC)
		ft_quit(i);
	return (0);
}

void	right_turn(t_info *i)
{
	double	olddirx;
	double	oldplane_x;

	olddirx = i->pla.dirx;
	i->pla.dirx = i->pla.dirx * cos(-SENS * SP_ROT)
		- i->pla.diry * sin(-SENS * SP_ROT);
	i->pla.diry = olddirx * sin(-SENS * SP_ROT)
		+ i->pla.diry * cos(-SENS * SP_ROT);
	oldplane_x = i->pla.plane_x;
	i->pla.plane_x = i->pla.plane_x * cos(-SENS * SP_ROT)
		- i->pla.plane_y * sin(-SENS * SP_ROT);
	i->pla.plane_y = oldplane_x * sin(-SENS * SP_ROT)
		+ i->pla.plane_y * cos(-SENS * SP_ROT);
}

void	left_turn(t_info *i)
{
	double	olddirx;
	double	oldplane_x;

	olddirx = i->pla.dirx;
	i->pla.dirx = i->pla.dirx * cos(SENS * SP_ROT)
		- i->pla.diry * sin(SENS * SP_ROT);
	i->pla.diry = olddirx * sin(SENS * SP_ROT)
		+ i->pla.diry * cos(SENS * SP_ROT);
	oldplane_x = i->pla.plane_x;
	i->pla.plane_x = i->pla.plane_x * cos(SENS * SP_ROT)
		- i->pla.plane_y * sin(SENS * SP_ROT);
	i->pla.plane_y = oldplane_x * sin(SENS * SP_ROT)
		+ i->pla.plane_y * cos(SENS * SP_ROT);
}
