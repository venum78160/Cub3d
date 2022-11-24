/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:01:38 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/24 17:48:42 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	msg_exit(char *string)
{
	printf("❌ ");
	ft_putstr_fd(string, 2);
	exit(1);
}

int	ft_quit(t_info *i)
{
	mlx_destroy_window(i->mlx, i->mlx_win);
	free_all(i);
	exit(1);
	return (EXIT_SUCCESS);
}

void	ft_door_test(void)
{
	close(ft_open("./texture/door/door_close.xpm"));
	close(ft_open("./texture/door/door_1.xpm"));
	close(ft_open("./texture/door/door_2.xpm"));
	close(ft_open("./texture/door/door_3.xpm"));
	close(ft_open("./texture/door/door_4.xpm"));
	close(ft_open("./texture/door/door_5.xpm"));
}

void	text_init(t_info *i)
{
	int	x;
	int	y;

	ft_door_test();
	i->text.count = PORTE_T;
	i->text.door_close = ft_calloc(sizeof(t_data), 1);
		i->text.door_close->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_close.xpm", &x, &y);
		i->text.door_close->addr = mlx_get_data_addr(i->text.door_close->img,
			&i->text.door_close->bppixel,
			&i->text.door_close->line_length, &i->text.door_close->endian);
	i->text.door_1 = ft_calloc(sizeof(t_data), 1);
		i->text.door_1->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_1.xpm", &x, &y);
		i->text.door_1->addr = mlx_get_data_addr(i->text.door_1->img,
			&i->text.door_1->bppixel, &i->text.door_1->line_length,
			&i->text.door_1->endian);
	i->text.door_2 = ft_calloc(sizeof(t_data), 1);
		i->text.door_2->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_2.xpm", &x, &y);
		i->text.door_2->addr = mlx_get_data_addr(i->text.door_2->img,
			&i->text.door_2->bppixel,
			&i->text.door_2->line_length, &i->text.door_2->endian);
	text_init2(i, x, y);
}

void	text_init2(t_info *i, int x, int y)
{
	i->text.door_3 = ft_calloc(sizeof(t_data), 1);
		i->text.door_3->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_3.xpm", &x, &y);
		i->text.door_3->addr = mlx_get_data_addr(i->text.door_3->img,
			&i->text.door_3->bppixel,
			&i->text.door_3->line_length, &i->text.door_3->endian);
	i->text.door_4 = ft_calloc(sizeof(t_data), 1);
		i->text.door_4->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_4.xpm", &x, &y);
		i->text.door_4->addr = mlx_get_data_addr(i->text.door_4->img,
			&i->text.door_4->bppixel,
			&i->text.door_4->line_length, &i->text.door_4->endian);
	i->text.door_5 = ft_calloc(sizeof(t_data), 1);
		i->text.door_5->img = mlx_xpm_file_to_image(i->mlx,
			"./texture/door/door_5.xpm", &x, &y);
		i->text.door_5->addr = mlx_get_data_addr(i->text.door_5->img,
			&i->text.door_5->bppixel,
			&i->text.door_5->line_length, &i->text.door_5->endian);
}
