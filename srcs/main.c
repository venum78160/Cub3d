/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:02:26 by lhotellier        #+#    #+#             */
/*   Updated: 2022/10/20 14:13:54 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	render(t_info *i)
{
	mlx_put_image_to_window(i->st_img.mlx, i->st_img.mlx_win, i->st_img.img, 0, 0);
	return (1);
}

void parsing(t_info *i)
{
	char **result;

	result = ft_calloc(sizeof(char *), 6);
	result[0] = ft_strdup("11111");
	result[1] = ft_strdup("10001");
	result[2] = ft_strdup("10001");
	result[3] = ft_strdup("10N01");
	result[4] = ft_strdup("11111");
	i->map = result;
}

int main(int argc, char **argv)
{
	t_info	i;
	
	if(argc != 2)
		msg_exit("Error: please use a correct format.\n");
	i.st_img.mlx = mlx_init();
	i.st_img.mlx_win = mlx_new_window(i.st_img.mlx, 700, 700, "Best Game");
	i.st_img.img = mlx_new_image(i.st_img.mlx, 700, 700);
	i.st_img.addr = mlx_get_data_addr(i.st_img.img,
			&i.st_img.bppixel, &i.st_img.line_length, &i.st_img.endian);
	i.i_map.name_fichier = argv[1];
	parsing(&i);
	mlx_loop_hook(i.st_img.mlx, render, &i);
	mlx_loop(i.st_img.mlx);
}