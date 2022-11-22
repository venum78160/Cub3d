/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:02:26 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/22 20:34:14 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_info *i)
{
	int x;

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

void	put_pixel_image(t_info *i, t_data *data, int x, int y)
{
	get_color(data, i->text.texX, i->text.texY);
	my_mlx_pixel_put(&i->st_img, x, y, *(int *)data->color);
}

int hide_mouse(int keycode, t_info *i)
{
	static int is_show = 0;
	
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
	static int last_x;

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

int free_all(t_info *info)
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
	
	if(argc != 2)
		msg_exit("Error: please use a correct format.\n");
	i.mlx = mlx_init();
	i.mlx_win = mlx_new_window(i.mlx, WIDTH, HEIGHT, "CUB_3D");
	i.st_img.img = mlx_new_image(i.mlx, WIDTH, HEIGHT);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	i.i_map.name_fichier = argv[1];
	parsing_v2(&i, argv[1]);
	printf("before render\n");
	printf("planex = %f, planeY = %f, dirX = %f, dirY = %f\n", i.pla.planeX, i.pla.planeY, i.pla.dirX, i.pla.dirY);

	mlx_mouse_hide();
	mlx_loop_hook(i.mlx, render, &i);
	mlx_hook(i.mlx_win, 2, 1L<<0, keyevent, &i);
	mlx_hook(i.mlx_win, 6, 0L, mouse_moove, &i);
	mlx_mouse_hook(i.mlx_win, hide_mouse, &i);
	mlx_loop(i.mlx);
	free_all(&i);
}