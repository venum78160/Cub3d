/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:34:07 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/11 16:57:08 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_mob(t_info *i, t_rect va)
{
	int	n;

	n = -1;
	while (++n < i->map.nbr_ennemi)
	{
		if (va.m_x == i->ennemi[n].x && va.m_y == i->ennemi[n].y)
			mlx_put_image_to_window(i->mlx, i->mlx_win, i->map.mob, va.x, va.y);
	}
}

int	key_hook(int keycode, void *vars)
{
	t_info	*i;

	i = (t_info *) vars;
	if (keycode == 0 || keycode == 123)
		move_left(i);
	else if (keycode == 1 || keycode == 125)
		move_down(i);
	else if (keycode == 2 || keycode == 124)
		move_right(i);
	else if (keycode == 13 || keycode == 126)
		move_up(i);
	else if (keycode == 53)
		ft_quit(i);
	else if (keycode == 15)
		i->dead = 1;
	return (0);
}

void	make_struct(t_info *i, char *fichier)
{
	i->map.coll = 0;
	i->map.exit = 0;
	i->map.nb_m = 0;
	i->map.player = 0;
	i->player.x = 0;
	i->player.y = 0;
	i->map.name_fichier = fichier;
	i->dead = 0;
	i->gg = 0;
	i->color = 0x00000001;
	i->map.nbr_ennemi = 0;
	make_struct2(i);
}

void	make_struct2(t_info *i)
{
	int	x;
	int	y;

	i->map.tree = mlx_xpm_file_to_image(i->mlx, "img_xpm/tree.xpm", &x, &y);
	i->map.coin = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin1.xpm", &x, &y);
	i->map.coin2 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin2.xpm", &x, &y);
	i->map.coin3 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin3.xpm", &x, &y);
	i->map.coin4 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin4.xpm", &x, &y);
	i->map.coin5 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin5.xpm", &x, &y);
	i->map.coin6 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin6.xpm", &x, &y);
	i->map.coin7 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin7.xpm", &x, &y);
	i->map.coin8 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin8.xpm", &x, &y);
	i->map.coin9 = mlx_xpm_file_to_image(i->mlx, "img_xpm/coin9.xpm", &x, &y);
	i->map.over = mlx_xpm_file_to_image(i->mlx, "img_xpm/xburn.xpm", &x, &y);
	i->map.gr = mlx_xpm_file_to_image(i->mlx, "img_xpm/grassx.xpm", &x, &y);
	i->map.hero = mlx_xpm_file_to_image(i->mlx, "img_xpm/hero.xpm", &x, &y);
	i->map.portail1 = mlx_xpm_file_to_image(i->mlx, "img_xpm/p1.xpm", &x, &y);
	i->map.portail2 = mlx_xpm_file_to_image(i->mlx, "img_xpm/p2.xpm", &x, &y);
	i->map.portail3 = mlx_xpm_file_to_image(i->mlx, "img_xpm/p3.xpm", &x, &y);
	i->map.portail4 = mlx_xpm_file_to_image(i->mlx, "img_xpm/p4.xpm", &x, &y);
	i->map.gg = mlx_xpm_file_to_image(i->mlx, "img_xpm/gg.xpm", &x, &y);
	i->map.mob = mlx_xpm_file_to_image(i->mlx, "img_xpm/bomb.xpm", &x, &y);
}

int	main(int argc, char *argv[])
{
	t_info	i;

	if (argc != 2)
		msg_exit("mauvais nombre d'argument");
	i.mlx = mlx_init();
	i.mlx_win = mlx_new_window(i.mlx, 700, 700, "Best Game");
	i.st_img.img = mlx_new_image(i.mlx, 700, 700);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	make_struct(&i, argv[1]);
	make_tab(&i);
	mlx_key_hook(i.mlx_win, key_hook, &i);
	mlx_loop_hook(i.mlx, render, &i);
	mlx_hook(i.mlx_win, 17, 0L, ft_quit, &i);
	mlx_loop(i.mlx);
	return (0);
}
