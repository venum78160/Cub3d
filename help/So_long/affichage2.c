/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:52:01 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/12/08 16:06:44 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_coin(t_info *i, int x, int y)
{
	static int	rotation = 1;

	sprite_grass(i, x - 15, y - 15);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x - 5, y - 5);
	if (rotation >= 1 && rotation <= 50)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin, x, y);
	else if (rotation >= 51 && rotation <= 102)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin2, x, y);
	else if (rotation >= 103 && rotation <= 154)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin3, x, y);
	else if (rotation >= 155 && rotation <= 206)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin4, x, y);
	else if (rotation >= 207 && rotation <= 258)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin5, x, y);
	else if (rotation >= 259 && rotation <= 310)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin6, x, y);
	else if (rotation >= 311 && rotation <= 362)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin7, x, y);
	else if (rotation >= 363 && rotation <= 414)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin8, x, y);
	else if (rotation >= 415 && rotation <= 466)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.coin9, x, y);
	rotation = rotation % 466;
	rotation++;
}

void	display_portal(t_info *i, int x, int y)
{
	static int	rotation = 1;

	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x - 5, y + 10);
	if (rotation >= 1 && rotation <= 30)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.portail1, x, y);
	else if (rotation >= 31 && rotation <= 62)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.portail2, x, y);
	else if (rotation >= 63 && rotation <= 94)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.portail3, x, y);
	else if (rotation >= 95 && rotation <= 126)
		mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.portail4, x, y);
	if (rotation >= 126)
		rotation = 0;
	rotation++;
}

void	move_mob(t_info *i)
{
	int	n;

	n = 0;
	if (i->map.nbr_ennemi == 0)
		return ;
	while (n < i->map.nbr_ennemi)
	{
		if (i->ennemi[n].neg == 1
			&& i->map.map_s[i->ennemi[n].y][i->ennemi[n].x + 1] == '1')
			i->ennemi[n].neg = -1;
		else if (i->ennemi[n].neg == -1
			&& i->map.map_s[i->ennemi[n].y][i->ennemi[n].x - 1] == '1')
			i->ennemi[n].neg = 1;
		if (i->player.x == i->ennemi[n].x
			&& i->player.y == i->ennemi[n].y)
			i->dead = 1;
		i->ennemi[n].x += i->ennemi[n].neg;
		if (i->player.x == i->ennemi[n].x
			&& i->player.y == i->ennemi[n].y)
			i->dead = 1;
		n++;
	}
}

void	sprite_grass(t_info *i, int x, int y)
{
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x + 10, y + 10);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x, y + 18);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.gr, x + 18, y);
}

void	rendercadre(t_info *i)
{
	ml_rect(*i, (t_rect){0, 700, 0, 126}, i->color);
	ml_rect(*i, (t_rect){0, 700, 574, 700}, i->color);
	mlx_string_put(i->mlx, i->mlx_win, 10, 200, 0x00FFFFFF, "Coin :");
	mlx_string_put(i->mlx, i->mlx_win, 10, 220, 0x00FFFFFF, "Move :");
	mlx_string_put(i->mlx, i->mlx_win, 80, 200, 0xFFFFFF, ft_itoa(i->map.coll));
	mlx_string_put(i->mlx, i->mlx_win, 80, 220, 0xFFFFFF, ft_itoa(i->map.nb_m));
	i->color += 1;
}
