/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:02:26 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/24 18:06:44 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_info *i)
{
	int	x;

	if (i->text.count < PORTE_T)
		i->text.count++;
	x = -1;
	backgroud(i);
	while (++x < WIDTH)
	{
		init_ray(i, x);
		print_text(i, x);
	}
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->st_img.img, 0, 0);
	minimap(i);
	return (1);
}

int	free_all(t_info *info)
{
	int	i;

	i = 0;
	free(info->text.text_S);
	free(info->text.text_N);
	free(info->text.text_W);
	free(info->text.text_E);
	while (info->map[i])
		free(info->map[i++]);
	free(info->map);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	i;

	if (argc != 2)
		msg_exit("Error: please use a correct format.\n");
	i.mlx = mlx_init();
	i.mlx_win = mlx_new_window(i.mlx, WIDTH, HEIGHT, "CUB_3D");
	i.st_img.img = mlx_new_image(i.mlx, WIDTH, HEIGHT);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	parsing_v2(&i, argv[1]);
	text_init(&i);
	mlx_mouse_hide();
	mlx_loop_hook(i.mlx, render, &i);
	mlx_hook(i.mlx_win, 2, 1L << 0, keyevent, &i);
	mlx_hook(i.mlx_win, 6, 0L, mouse_moove, &i);
	mlx_mouse_hook(i.mlx_win, hide_mouse, &i);
	mlx_loop(i.mlx);
	free_all(&i);
}
