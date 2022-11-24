/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonct_mv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:12:15 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/24 18:26:56 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	mv_up(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.dirx * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x += i->pla.dirx * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.diry * SPEED)]))
		i->pla.pl_y += i->pla.diry * SPEED;
}

void	mv_down(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.dirx * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x -= i->pla.dirx * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.diry * SPEED)]))
		i->pla.pl_y -= i->pla.diry * SPEED;
}

void	mv_left(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x - i->pla.plane_x * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x -= i->pla.plane_x * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y - i->pla.plane_y * SPEED)]))
		i->pla.pl_y -= i->pla.plane_y * SPEED;
}

void	mv_right(t_info	*i)
{
	if (no_hitbox(i->map[(int)(i->pla.pl_x + i->pla.plane_x * SPEED)]
		[(int)i->pla.pl_y]))
		i->pla.pl_x += i->pla.plane_x * SPEED;
	if (no_hitbox(i->map[(int)i->pla.pl_x]
			[(int)(i->pla.pl_y + i->pla.plane_y * SPEED)]))
		i->pla.pl_y += i->pla.plane_y * SPEED;
}
