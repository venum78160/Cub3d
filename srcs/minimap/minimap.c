/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:07:49 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/22 19:28:36 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	minimap(t_info	*i)
{
	printf("debut minimap\n");
	ml_rect(*i, (t_rect){LOC_MAP_Y, LOC_MAP_Y + SIZE_BLOCK_MAP * NBR_BL_MAP, LOC_MAP_X, LOC_MAP_X + SIZE_BLOCK_MAP * NBR_BL_MAP}, 0x00EEEEE4);
	// printf("%i\n",LOC_MAP_Y + SIZE_BLOCK_MAP * NBR_BL_MAP);
	ml_case(i, ml_fond_case);
	mlx_put_image_to_window(i->mlx, i->mlx_win, i->st_img.img, 0, 0);
}

void	ml_case(t_info *i, void (*fonction)())
{
	int	x;
	int	y;

	x = LOC_MAP_Y;
	while (x < (LOC_MAP_Y + SIZE_BLOCK_MAP * NBR_BL_MAP))
	{
		y = LOC_MAP_X;
		while (y < (LOC_MAP_X + SIZE_BLOCK_MAP * NBR_BL_MAP))
		{
			fonction(x, y, i);
			y += SIZE_BLOCK_MAP;
		}
		x += SIZE_BLOCK_MAP;
	}
	printf("end boucle\n\n\n");
}

void	ml_rect(t_info info, t_rect rect, int color)
{
	int	ybis;

	rect.x--;
	while (++rect.x <= rect.m_x)
	{
		ybis = rect.y - 1;
		while (++ybis < rect.m_y)
			my_mlx_pixel_put(&info.st_img, rect.x, ybis, color);
	}
	return ;
}

void	ml_fond_case(int x, int y, t_info *i)
{
	int	ind_x;
	int	ind_y;

	ind_x = i->pla.pl_x - 5 + ((x - LOC_MAP_X) / SIZE_BLOCK_MAP);
	ind_y = i->pla.pl_y - 5 + ((y - LOC_MAP_Y) / SIZE_BLOCK_MAP);
	printf("\n[fond case] pl_x =%f, pl_y =%f\n", i->pla.pl_x, i->pla.pl_y);
	printf("int pl_x=%i, pl_y =%i\n", (int)i->pla.pl_x, (int)i->pla.pl_y);
	printf("[fond case] x =%i, y =%i\n", ind_x, ind_y);
	// printf("strlen %i\n", ft_strlen2star(i->map));
	// printf("len %i\n", (int)ft_strlen(i->map[ind_x]));
	if (ind_x < 0 || ind_y < 0)
		ml_rect(*i, (t_rect){y, y + SIZE_BLOCK_MAP, x, x + SIZE_BLOCK_MAP}, 0x00FF0000);
	else if (ind_x >= ft_strlen2star(i->map) || ind_y >= (int)ft_strlen(i->map[ind_x]))
	{
		ml_rect(*i, (t_rect){y, y + SIZE_BLOCK_MAP, x, x + SIZE_BLOCK_MAP}, 0x00FF0000);
	}
	else if (ind_x == (int)i->pla.pl_x && ind_y == (int)i->pla.pl_y)
	{
		ml_rect(*i, (t_rect){y, y + SIZE_BLOCK_MAP, x, x + SIZE_BLOCK_MAP}, 0x00499848);
	}
	else if ( i->map[ind_x][ind_y] == '1')
		ml_rect(*i, (t_rect){y, y + SIZE_BLOCK_MAP, x, x + SIZE_BLOCK_MAP}, 0x00FF0000);
	else if ( i->map[ind_x][ind_y] == 'P' || i->map[ind_x][ind_y] == 'O')
		ml_rect(*i, (t_rect){y, y + SIZE_BLOCK_MAP, x, x + SIZE_BLOCK_MAP}, 0x00FF0000);
}

// #eeeee4