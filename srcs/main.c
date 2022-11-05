/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:02:26 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/05 18:47:57 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_quit(t_info *i)
{
	mlx_destroy_window(i->st_img.mlx, i->st_img.mlx_win);
	// ft_del_maps (i, "exit");
	exit(1);
	return (EXIT_SUCCESS);
}

int	render(t_info *i)
{
	int x;

	x = -1;
	while (++x < WIDTH)
	{
		init_ray(i, x);
		print_text(i, x);
	}
	mlx_put_image_to_window(i->st_img.mlx, i->st_img.mlx_win, i->st_img.img, 0, 0);
	// printf("end render\n");
	// i->color += 1;
	return (1);
}

void	print_text(t_info *i, int x)
{
	// printf("print text\n");
	if (!i->pla.side)
		i->pla.dist_wall = i->pla.side_disX - i->pla.delta_X;
	else
		i->pla.dist_wall = i->pla.side_disY - i->pla.delta_Y;
	i->pla.line_h = (int)(HEIGHT / i->pla.dist_wall);
	// int t = HEIGHT;
	// printf("line h = %i, HEIGHT = %i, dist_wall %f\n", i->pla.line_h, t, i->pla.dist_wall);
	i->pla.draw_start = -1 * i->pla.line_h / 2.0 + HEIGHT / 2.0 + 1;
	if (i->pla.draw_start < 0)
		i->pla.draw_start = 0;
	i->pla.draw_end = i->pla.line_h / 2.0 + HEIGHT / 2.0;
	if (i->pla.draw_end >= HEIGHT)
		i->pla.draw_end = HEIGHT - 1;
	print_line_wall(x, i, 0x00FF0000);
}

void	print_line_wall(int x, t_info *i, int color)
{
	int y;

	y = i->pla.draw_start;
	// printf("valeur de x = %i, valeur de y %i, draw_end %i\n", x, y, i->pla.draw_end);
	while (y <= i->pla.draw_end)
	{
		my_mlx_pixel_put(&i->st_img, x, y, color);
		y++;
	}
}

void	init_ray(t_info *i, int x)
{
	// printf("begin init ray\n");
	i->pla.cameraX = 2 * x / (double)(WIDTH)-1;
	i->pla.rayDirX = i->pla.dirX + i->pla.planeX * i->pla.cameraX;
	i->pla.rayDirY = i->pla.dirY + i->pla.planeY * i->pla.cameraX;
	i->pla.mapX = (int)i->pla.pl_x;
	i->pla.mapY = (int)i->pla.pl_y;
	if (!i->pla.rayDirX)
		i->pla.delta_X = INFINITY;
	else
		i->pla.delta_X = fabs(1 / i->pla.rayDirX);
	if (!i->pla.rayDirY)
		i->pla.delta_Y = INFINITY;
	else
		i->pla.delta_Y = fabs(1 / i->pla.rayDirX);
	i->pla.hit = 0;
	step(i);
	dda(i);
	// printf("end init ray\n");
}

void	step(t_info *i)
{
	// printf("begin step\n");
	if (i->pla.rayDirX < 0)
	{
		i->pla.step_x = -1;
		i->pla.side_disX = (i->pla.pl_x - i->pla.mapX) * i->pla.delta_X;
	}
	else
	{
		i->pla.step_x = 1;
		i->pla.side_disX = (i->pla.mapX + 1.0 - i->pla.pl_x) * i->pla.delta_X;
	}
	if (i->pla.rayDirY < 0)
	{
		i->pla.step_y = -1;
		i->pla.side_disY = (i->pla.pl_y - i->pla.mapY) * i->pla.delta_Y;
	}
	else
	{
		i->pla.step_y = 1;
		i->pla.side_disY = (i->pla.mapY + 1.0 - i->pla.pl_y) * i->pla.delta_Y;
	}
}

void	dda(t_info *i)
{
	// printf("begin dda\n");
	while (i->pla.hit == 0)
	{
		// printf("boucle dda\n");
		if (i->pla.side_disX < i->pla.side_disY)
		{
			// printf("side X < side Y\n");
			i->pla.side_disX += i->pla.delta_X;
			i->pla.mapX += i->pla.step_x;
			i->pla.side = 0;
		}
		else
		{
			// printf("side Y\n");
			// printf("%i,%i\n", i->pla.mapY, i->pla.mapX);
			i->pla.side_disY += i->pla.delta_Y;
			i->pla.mapY += i->pla.step_y;
			i->pla.side = 1;
		}
		// printf("%i,%i\n", i->pla.mapY, i->pla.mapX);
		if (i->map[i->pla.mapX][i->pla.mapY] == '1')
		{
			// printf("hit %i%i\n\n", i->pla.mapY, i->pla.mapX);
			// printf("hit 1\n");
			i->pla.hit = 1;
		}
	}
	// printf("end dda\n");
}

void parsing(t_info *i)
{
	char **result;
	int j;

	result = ft_calloc(sizeof(char *), 8);
	result[0] = ft_strdup("11111");
	result[1] = ft_strdup("10001");
	result[2] = ft_strdup("10001");
	result[3] = ft_strdup("10N01");
	result[4] = ft_strdup("10001");
	result[5] = ft_strdup("10001");
	result[6] = ft_strdup("11111");
	i->map = result;
	j = 0;
	i->pla.pl_x = 2;
	i->pla.pl_y = 3;
	i->pla.dirX = 1;
	i->pla.dirY = 1; //initial direction vector
	i->pla.planeX = 0;
	i->pla.planeY = FOVY; //the 2d raycaster version of camera plane
	
  	i->pla.time = 0; //time of current frame
  	i->pla.oldtime = 0; //time of previous frame
	i->color = 00000000;
	while (i->map[j])
	{
		printf("%s\n", i->map[j]);
		j++;
	}
}

int	keyevent(int keyword, t_info *i)
{
	printf("key = %i\n", keyword);
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
	// if(keyword == LEFT)
	// {
		
	// }
	// if(keyword == RIGHT)
	// {
		
	// }
	if(keyword == ESC)
	{
		ft_quit(i);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	i;
	
	if(argc != 2)
		msg_exit("Error: please use a correct format.\n");
	i.st_img.mlx = mlx_init();
	i.st_img.mlx_win = mlx_new_window(i.st_img.mlx, WIDTH, HEIGHT, "Best Game");
	i.st_img.img = mlx_new_image(i.st_img.mlx, WIDTH, HEIGHT);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	i.i_map.name_fichier = argv[1];
	parsing(&i);
	printf("before render\n");
	mlx_loop_hook(i.st_img.mlx, render, &i);
	mlx_hook(i.st_img.mlx_win, 2, 1L<<0, keyevent, &i);
	mlx_loop(i.st_img.mlx);
}