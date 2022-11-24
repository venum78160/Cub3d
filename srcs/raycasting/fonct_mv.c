/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:12:15 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/23 21:22:23 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mv_up(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.dirX * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x += i->pla.dirX * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.dirY * SPEED)]))
		i->pla.pl_y += i->pla.dirY * SPEED;
}

void	mv_down(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.dirX * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x -= i->pla.dirX * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.dirY * SPEED)]))
		i->pla.pl_y -= i->pla.dirY * SPEED;
}

void	mv_left(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.planeX * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x -= i->pla.planeX * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.planeY * SPEED)]))
		i->pla.pl_y -= i->pla.planeY * SPEED;
}

void	mv_right(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.planeX * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x += i->pla.planeX * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.planeY * SPEED)]))
		i->pla.pl_y += i->pla.planeY * SPEED;
}
