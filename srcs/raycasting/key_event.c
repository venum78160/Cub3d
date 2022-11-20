/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:19:34 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/20 21:23:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	keyevent(int keyword, t_info *i)
{
	if(keyword == UP)
	{
		if (i->map[(int)(i->pla.pl_x + i->pla.dirX * SPEED)]
			[(int)i->pla.pl_y] != '1')
			i->pla.pl_x += i->pla.dirX * SPEED;
		if (i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.dirY * SPEED)] != '1')
			i->pla.pl_y += i->pla.dirY * SPEED;
	}
	if(keyword == DOWN)
	{
		if (i->map[(int)(i->pla.pl_x - i->pla.dirX * SPEED)]
			[(int)i->pla.pl_y] != '1')
			i->pla.pl_x -= i->pla.dirX * SPEED;
		if (i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.dirY * SPEED)] != '1')
			i->pla.pl_y -= i->pla.dirY * SPEED;
	}
	if(keyword == LEFT)
	{

		if (i->map[(int)(i->pla.pl_x - i->pla.planeX * SPEED)]
			[(int)i->pla.pl_y] != '1')
			i->pla.pl_x -= i->pla.planeX * SPEED;
		if (i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.planeY * SPEED)] != '1')
			i->pla.pl_y -= i->pla.planeY * SPEED;
	}
	if(keyword == RIGHT)
	{
		if (i->map[(int)(i->pla.pl_x + i->pla.planeX * SPEED)]
			[(int)i->pla.pl_y] != '1')
			i->pla.pl_x += i->pla.planeX * SPEED;
		if (i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.planeY * SPEED)] != '1')
			i->pla.pl_y += i->pla.planeY * SPEED;
	}
	if(keyword == ARROW_R)
		right_turn(i);
	if(keyword == ARROW_L)
		left_turn(i);
	if(keyword == ESC)
	{
		ft_quit(i);
	}
	return (0);
}

void	right_turn(t_info *i)
{
	double oldDirX;

	oldDirX = i->pla.dirX;
	i->pla.dirX = i->pla.dirX * cos(-SENSIVITY * SPEED_ROT) - i->pla.dirY * sin(-SENSIVITY * SPEED_ROT);
	i->pla.dirY = oldDirX * sin(-SENSIVITY * SPEED_ROT) + i->pla.dirY * cos(-SENSIVITY * SPEED_ROT);
	double oldPlaneX;
	oldPlaneX = i->pla.planeX;
	i->pla.planeX = i->pla.planeX * cos(-SENSIVITY * SPEED_ROT) - i->pla.planeY * sin(-SENSIVITY * SPEED_ROT);
	i->pla.planeY = oldPlaneX * sin(-SENSIVITY * SPEED_ROT) + i->pla.planeY * cos(-SENSIVITY * SPEED_ROT);
}

void	left_turn(t_info *i)
{
	double oldDirX;

	oldDirX = i->pla.dirX;
	i->pla.dirX = i->pla.dirX * cos(SENSIVITY * SPEED_ROT) - i->pla.dirY * sin(SENSIVITY * SPEED_ROT);
	i->pla.dirY = oldDirX * sin(SENSIVITY * SPEED_ROT) + i->pla.dirY * cos(SENSIVITY * SPEED_ROT);
	double oldPlaneX;
	oldPlaneX = i->pla.planeX;
	i->pla.planeX = i->pla.planeX * cos(SENSIVITY * SPEED_ROT) - i->pla.planeY * sin(SENSIVITY * SPEED_ROT);
	i->pla.planeY = oldPlaneX * sin(SENSIVITY * SPEED_ROT) + i->pla.planeY * cos(SENSIVITY * SPEED_ROT);
}