/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deplacement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:04:14 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/05 17:37:21 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_down(t_info *i)
{
	if (i->map.map_s[i->pla.y + 1][i->pla.x] == '1')
		return (0);
	else if (i->map.map_s[i->pla.y + 1][i->pla.x] == 'E'
		&& i->map.coll == 0)
		i->gg = 1;
	else if (i->map.map_s[i->pla.y + 1][i->pla.x] == 'C')
	{
		i->map.coll--;
		i->map.map_s[i->pla.y + 1][i->pla.x] = '0';
	}
	i->pla.y += 1;
	i->map.nb_m++;
	verif_dead(i);
	return (1);
}

int	move_up(t_info *i)
{
	if (i->map.map_s[i->pla.y - 1][i->pla.x] == '1')
		return (0);
	else if (i->map.map_s[i->pla.y - 1][i->pla.x] == 'E'
		&& i->map.coll == 0)
		i->gg = 1;
	else if (i->map.map_s[i->pla.y - 1][i->pla.x] == 'C')
	{
		i->map.coll--;
		i->map.map_s[i->pla.y - 1][i->pla.x] = '0';
	}
	i->pla.y += -1;
	i->map.nb_m++;
	verif_dead(i);
	return (1);
}

int	move_left(t_info *i)
{
	if (i->map.map_s[i->pla.y][i->pla.x - 1] == '1')
		return (0);
	else if (i->map.map_s[i->pla.y][i->pla.x - 1] == 'E'
		&& i->map.coll == 0)
		i->gg = 1;
	else if (i->map.map_s[i->pla.y][i->pla.x - 1] == 'C')
	{
		i->map.coll--;
		i->map.map_s[i->pla.y][i->pla.x - 1] = '0';
	}
	i->pla.x += -1;
	i->map.nb_m++;
	verif_dead(i);
	return (1);
}

int	move_right(t_info *i)
{
	if (i->map.map_s[i->pla.y][i->pla.x + 1] == '1')
		return (0);
	else if (i->map.map_s[i->pla.y][i->pla.x + 1] == 'E'
		&& i->map.coll == 0)
		i->gg = 1;
	else if (i->map.map_s[i->pla.y][i->pla.x + 1] == 'C')
	{
		i->map.coll--;
		i->map.map_s[i->pla.y][i->pla.x + 1] = '0';
	}
	i->pla.x += 1;
	i->map.nb_m++;
	verif_dead(i);
	return (1);
}

void	verif_dead(t_info *i)
{
	int	n;

	n = 0;
	while (n < i->map.nbr_ennemi)
	{
		if (i->pla.x == i->ennemi[n].x && i->pla.y == i->ennemi[n].y)
			i->dead = 1;
		n++;
	}
}
