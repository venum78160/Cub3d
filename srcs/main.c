/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:02:26 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/18 15:26:27 by mgoudin          ###   ########.fr       */
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

void	backgroud(t_info *i)
{
	int x;
	int y;

	x = -1;
	while (++x <= WIDTH)
	{
		y = -1;
		while (++y <= HEIGHT)
		{
			if( y <= (HEIGHT / 2))
				my_mlx_pixel_put(&i->st_img, x, y, i->ceiling_c);
			else
				my_mlx_pixel_put(&i->st_img, x, y, i->floor_c);
		}
	}
	mlx_put_image_to_window(i->st_img.mlx, i->st_img.mlx_win, i->st_img.img, 0, 0);
}
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
		i->pla.draw_end = HEIGHT + 1;

	if (i->pla.side)
		i->text.wallx = i->pla.pl_y + i->pla.dist_wall * i->pla.rayDirY;
	else
		i->text.wallx = i->pla.pl_x + i->pla.dist_wall * i->pla.rayDirX;
	i->text.wallx -= floor(i->text.wallx);
	i->text.texX = (int)(i->text.wallx * (double)TEXT_SIZE);
	if (!i->pla.side && i->pla.rayDirX > 0)
		i->text.texX = TEXT_SIZE - i->text.texX;
	if (i->pla.side && i->pla.rayDirX < 0)
		i->text.texX = TEXT_SIZE - i->text.texX;
	print_line_wall(x, i, 0x00FF0000);
}

void	print_line_wall(int x, t_info *i, int color)
{
	int y;

	y = i->pla.draw_start;
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
		i->pla.delta_Y = fabs(1 / i->pla.rayDirY);
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

void	print_map(char **map)
{
	int	i;

	i = 0;
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void parsing(t_info *i)
{
	char **result;
	int j;
	int x;
	int y;

	result = ft_calloc(sizeof(char *), 9);
	result[0] = ft_strdup("11111111111111111111111");
	result[1] = ft_strdup("10000000111100000000001");
	result[2] = ft_strdup("10000000000000000000001");
	result[3] = ft_strdup("11N00000000000000000001");
	result[4] = ft_strdup("10000000000000000000001");
	result[5] = ft_strdup("10000000111100000000001");
	result[6] = ft_strdup("10000000111100000000001");
	result[7] = ft_strdup("11111111111111111111111");
	i->map = result;
	j = 0;
	i->pla.pl_x = 2.5;
	i->pla.pl_y = 3.5;
	i->pla.dirX = 0;
	i->pla.dirY = 1; //initial direction vector
	i->pla.planeX = 0;
	i->pla.planeY = FOVY; //the 2d raycaster version of camera plane
	
  	i->pla.time = 0; //time of current frame
  	i->pla.oldtime = 0; //time of previous frame
	i->floor_c = 206206206;
	i->ceiling_c = 119181254;
	i->text.text_N = mlx_xpm_file_to_image(i->st_img.mlx , "./textures/jungle/acacia_leaves_opaque.xpm", &x, &y);
	i->text.text_S = mlx_xpm_file_to_image(i->st_img.mlx , "./textures/jungle/jungle_leaves_opaque.xpm", &x, &y);
	i->text.text_W = mlx_xpm_file_to_image(i->st_img.mlx , "./textures/jungle/grass_block.xpm", &x, &y);
	i->text.text_E = mlx_xpm_file_to_image(i->st_img.mlx , "./textures/jungle/jungle_log_top.xpm", &x, &y);
}

int	keyevent(int keyword, t_info *i)
{
	printf("key = %i\n", keyword);
	printf("pose jouer y[%f]x[%f]\n", i->pla.pl_y, i->pla.pl_x);
	printf("drawn start[%i]drawn end[%i]\n", i->pla.draw_start, i->pla.draw_end);
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
	{
		double oldDirX;
		oldDirX = i->pla.dirX;
		i->pla.dirX = i->pla.dirX * cos(-1 * SPEED_ROT) - i->pla.dirY * sin(-1 * SPEED_ROT);
      	i->pla.dirY = oldDirX * sin(-1 * SPEED_ROT) + i->pla.dirY * cos(-1 * SPEED_ROT);
      	double oldPlaneX;
		oldPlaneX = i->pla.planeX;
      	i->pla.planeX = i->pla.planeX * cos(-1 * SPEED_ROT) - i->pla.planeY * sin(-1 * SPEED_ROT);
		i->pla.planeY = oldPlaneX * sin(-1 * SPEED_ROT) + i->pla.planeY * cos(-1 * SPEED_ROT);
	}
	if(keyword == ARROW_L)
	{
		double oldDirX;
		oldDirX = i->pla.dirX;
		i->pla.dirX = i->pla.dirX * cos(SPEED_ROT) - i->pla.dirY * sin(SPEED_ROT);
      	i->pla.dirY = oldDirX * sin(SPEED_ROT) + i->pla.dirY * cos(SPEED_ROT);
      	double oldPlaneX;
		oldPlaneX = i->pla.planeX;
      	i->pla.planeX = i->pla.planeX * cos(SPEED_ROT) - i->pla.planeY * sin(SPEED_ROT);
		i->pla.planeY = oldPlaneX * sin(SPEED_ROT) + i->pla.planeY * cos(SPEED_ROT);
	}
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

int	mouse_moove(int x, int y, t_info *i)
{
	static int last_x;

	if (!last_x)
		last_x = WIDTH / 2;
	if (x > last_x)
		right_turn(i);
	if (x < last_x)
		left_turn(i);
	last_x = x;
	(void)y;
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	i;
	
	if(argc != 2)
		msg_exit("Error: please use a correct format.\n");
	i.st_img.mlx = mlx_init();
	i.st_img.mlx_win = mlx_new_window(i.st_img.mlx, WIDTH, HEIGHT, "CUB_3D");
	i.st_img.img = mlx_new_image(i.st_img.mlx, WIDTH, HEIGHT);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	i.i_map.name_fichier = argv[1];
	//parsing(&i);
	parsing_v2(&i, argv[1]);
	print_map(i.map);
	printf("PlaneX %f\n", i.pla.planeX);
	printf("PlaneY %f\n", i.pla.planeY);
	printf("time %f\n", i.pla.time);
	printf("time %f\n", i.pla.oldtime);
	printf("X %f\n", i.pla.pl_x);
	printf("Y %f\n", i.pla.pl_y);
	printf("dirX %f\n", i.pla.dirX);
	printf("dirY %f\n", i.pla.dirY);
	printf("before render\n");
	mlx_loop_hook(i.st_img.mlx, render, &i);
	mlx_hook(i.st_img.mlx_win, 2, 1L<<0, keyevent, &i);
	mlx_hook(i.st_img.mlx_win, 6, 0L, mouse_moove, &i);
	mlx_loop(i.st_img.mlx);
}