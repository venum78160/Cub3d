/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 21:17:49 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/22 22:59:20 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_text(t_info *i, int x)
{
	if (!i->pla.side)
		i->pla.dist_wall = i->pla.side_disX - i->pla.delta_X;
	else
		i->pla.dist_wall = i->pla.side_disY - i->pla.delta_Y;
	i->pla.line_h = (int)(HEIGHT / i->pla.dist_wall);
	i->pla.draw_start = -1 * i->pla.line_h / 2.0 + HEIGHT / 2.0 + 1;
	if (i->pla.draw_start < 0)
		i->pla.draw_start = 0;
	i->pla.draw_end = i->pla.line_h / 2.0 + HEIGHT / 2.0;
	if (i->pla.draw_end >= HEIGHT)
		i->pla.draw_end = HEIGHT + 1;
	if (i->pla.side)
		i->text.wallx = i->pla.pl_x + i->pla.dist_wall * i->pla.rayDirX;
	else
		i->text.wallx = i->pla.pl_y + i->pla.dist_wall * i->pla.rayDirY;
	i->text.wallx -= floor(i->text.wallx);
	i->text.texX = (int)(i->text.wallx * (double)TEXT_SIZE);
	if (!i->pla.side && i->pla.rayDirX > 0)
		i->text.texX = TEXT_SIZE - i->text.texX;
	if (i->pla.side && i->pla.rayDirY < 0)
		i->text.texX = TEXT_SIZE - i->text.texX;
	print_line_wall(i, x);
}

void	text_door(t_info *i, int x, int y)
{
	if(i->text.count == 200)
		put_pixel_image(i, i->text.door_close, x, y);
	else if(i->text.count / 40 + 1 == 1)
		put_pixel_image(i, i->text.door_1, x, y);
	else if(i->text.count / 40 + 1 == 2)
		put_pixel_image(i, i->text.door_2, x, y);
	else if(i->text.count / 40 + 1 == 3)
		put_pixel_image(i, i->text.door_3, x, y);
	else if(i->text.count / 40 + 1 == 4)
		put_pixel_image(i, i->text.door_4, x, y);
	else if(i->text.count / 40 + 1 == 5)
		put_pixel_image(i, i->text.door_5, x, y);
}

void	print_line_wall(t_info *i, int x)
{
	int y;
	
	y = i->pla.draw_start;
	text_increaser(i, 0);
	while (y <= i->pla.draw_end)
	{
		text_increaser(i, 1);
		if(find_wall(i) == 'N')
			put_pixel_image(i, i->text.text_N, x, y);
		if(find_wall(i) == 'S')
			put_pixel_image(i, i->text.text_S, x, y);
		if(find_wall(i) == 'E')
			put_pixel_image(i, i->text.text_E, x, y);
		if(find_wall(i) == 'W')
			put_pixel_image(i, i->text.text_W, x, y);
		if(find_wall(i) == 'D')
			text_door(i, x, y);
		y++;
	}
}

void	text_increaser(t_info *i, int boucle)
{
	if(boucle == 0)
	{
		i->text.step = 1.0 * TEXT_SIZE / i->pla.line_h;
		i->text.textpos = (i->pla.draw_start - HEIGHT / 2.0 + i->pla.line_h / 2.0) * i->text.step;
	}
	else
	{
		i->text.texY = (int)i->text.textpos & (TEXT_SIZE - 1);
		i->text.texY += 1;
		i->text.textpos += i->text.step;
	}
}

char	find_wall(t_info *i)
{
	if (i->pla.side && i->pla.step_y < 0 && i->pla.hit)
		return ('W');
	else if (i->pla.side && i->pla.step_y > 0 && i->pla.hit)
		return ('E');
	else if (!i->pla.side && i->pla.step_x > 0 && i->pla.hit)
		return ('S');
	else if (!i->pla.side && i->pla.step_x < 0 && i->pla.hit)
		return ('N');
	else if (i->pla.hit_door)
		return ('D');
	else
		return ('P');
}