/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:19:34 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/22 22:47:26 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	no_hitbox(char c)
{
	if (c == '1')
		return (0);
	if (c == 'P')
		return (0);
	return (1);
}

char get_invert(int x, int y, t_info *info)
{
	if (info->map[x][y] == 'P')
		return ('O');
	return ('P');
}

int action_door(int x, int y, t_info *info)
{
	info->map[x][y] = get_invert(x, y, info);
	info->text.count = 0;
	return (1);
}

int is_door(char c)
{
	if (c == 'O')
		return (1);
	if (c == 'P')
		return (1);
	return (0);
}

void action_door_around(int x, int y, t_info *info)
{
	if (is_door(info->map[x + 1][y]))
		action_door(x + 1, y, info);
	if (is_door(info->map[x + 1][y + 1]))
		action_door(x + 1, y + 1, info);
	if (is_door(info->map[x + 1][y - 1]))
		action_door(x + 1, y - 1, info);
	if (is_door(info->map[x][y + 1]))
		action_door(x, y + 1, info);
	if (is_door(info->map[x][y - 1]))
		action_door(x, y - 1, info);
	if (is_door(info->map[x - 1][y - 1]))
		action_door(x - 1, y - 1, info);
	if (is_door(info->map[x - 1][y]))
		action_door(x - 1, y, info);
	if (is_door(info->map[x - 1][y + 1]))
		action_door(x - 1, y + 1, info);
}

int	keyevent(int keyword, t_info *i)
{
	if(keyword == UP)
	{
		if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.dirX * SPEED)]
			[(int)i->pla.pl_y]))
			i->pla.pl_x += i->pla.dirX * SPEED;
		if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.dirY * SPEED)]))
			i->pla.pl_y += i->pla.dirY * SPEED;
	}
	if(keyword == DOWN)
	{
		if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.dirX * SPEED)]
			[(int)i->pla.pl_y]))
			i->pla.pl_x -= i->pla.dirX * SPEED;
		if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.dirY * SPEED)]))
			i->pla.pl_y -= i->pla.dirY * SPEED;
	}
	if(keyword == LEFT)
	{

		if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.planeX * SPEED)]
			[(int)i->pla.pl_y]))
			i->pla.pl_x -= i->pla.planeX * SPEED;
		if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.planeY * SPEED)]))
			i->pla.pl_y -= i->pla.planeY * SPEED;
	}
	if(keyword == RIGHT)
	{
		if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.planeX * SPEED)]
			[(int)i->pla.pl_y]))
			i->pla.pl_x += i->pla.planeX * SPEED;
		if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.planeY * SPEED)]))
			i->pla.pl_y += i->pla.planeY * SPEED;
	}
	if (keyword == SPACE)
	{
		action_door_around((int)i->pla.pl_x, (int)i->pla.pl_y, i);
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