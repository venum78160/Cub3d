/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:49:54 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/12/10 16:51:50 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_info *i)
{
	static int	frame = 0;

	if (i->dead == 1)
	{
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.over, 50, 0);
		return (0);
	}
	if (i->gg == 1)
	{
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gg, 80, 10);
		return (0);
	}
	ml_case(i, ml_fond_case);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->st_img.img, 0, 0);
	ml_case(i, ml_sprite_case);
	rendercadre(i);
	if (frame == 0)
		move_mob(i);
	frame++;
	frame = frame % 15;
	return (0);
}

void	ml_case(t_info *i, void (*fonction)())
{
	int	x;
	int	y;

	y = 126;
	while (y < 574)
	{
		x = 126;
		while (x < 574)
		{
			fonction(x, y, i);
			x += 64;
		}
		y += 64;
	}
}

void	ml_fond_case(int x, int y, t_info *i)
{
	int	ind_x;
	int	ind_y;

	ind_x = i->player.x - 3 + ((x - 126) / 64);
	ind_y = i->player.y - 3 + ((y - 126) / 64);
	if (ind_x < 0 || ind_y < 0)
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (ind_x >= i->map.map_width || ind_y >= i->map.map_height)
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (ind_x == i->player.x && ind_y == i->player.y)
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (i->map.map_s[ind_y][ind_x] == '1')
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (i->map.map_s[ind_y][ind_x] == '0')
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (i->map.map_s[ind_y][ind_x] == 'C')
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (i->map.map_s[ind_y][ind_x] == 'D')
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
	else if (i->map.map_s[ind_y][ind_x] == 'E')
		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
}

void	ml_sprite_case(int x, int y, t_info *i)
{	
	int	ind_x;
	int	ind_y;

	ind_x = i->player.x - 3 + ((x - 126) / 64);
	ind_y = i->player.y - 3 + ((y - 126) / 64);
	if (ind_x < 0 || ind_y < 0)
		sprite_grasstree(i, x, y);
	else if (ind_x >= i->map.map_width || ind_y >= i->map.map_height)
		sprite_grasstree(i, x, y);
	else if (ind_x == i->player.x && ind_y == i->player.y)
	{
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x + 10, y + 10);
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.hero, x + 10, y + 5);
	}
	else if (i->map.map_s[ind_y][ind_x] == '1')
		sprite_grasstree(i, x, y);
	else if (i->map.map_s[ind_y][ind_x] == '0')
		sprite_grass(i, x, y);
	else if (i->map.map_s[ind_y][ind_x] == 'C')
		display_coin(i, x + 15, y + 15);
	else if (i->map.map_s[ind_y][ind_x] == 'E')
		display_portal(i, x + 15, y);
	display_mob(i, (t_rect){x, ind_x, y, ind_y});
}

void	sprite_grasstree(t_info *i, int x, int y)
{
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x, y);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x, y + 18);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x + 18, y);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x + 18, y + 18);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.tree, x + 10, y + 10);
}
