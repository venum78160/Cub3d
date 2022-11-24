/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 21:30:19 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/23 21:42:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	hide_mouse(int keycode, t_info *i)
{
	static int	is_show = 0;

	(void)i;
	if (keycode == 2)
	{
		if (!is_show)
		{
			mlx_mouse_show();
			is_show = 1;
		}
		else
		{
			mlx_mouse_hide();
			is_show = 0;
		}
	}
	return (0);
}

int	mouse_moove(int x, int y, t_info *i)
{
	static int	last_x;

	if (!last_x)
		last_x = WIDTH / 2;
	if (x > last_x)
		right_turn(i);
	if (x < last_x)
		left_turn(i);
	if (y > HEIGHT)
		mlx_mouse_move(i->mlx_win, x, HEIGHT / 2);
	if (y < 0)
		mlx_mouse_move(i->mlx_win, x, HEIGHT / 2);
	if (x > WIDTH)
		mlx_mouse_move(i->mlx_win, WIDTH / 2, HEIGHT / 2);
	if (x < 0)
		mlx_mouse_move(i->mlx_win, WIDTH / 2, HEIGHT / 2);
	last_x = x;
	return (0);
}
