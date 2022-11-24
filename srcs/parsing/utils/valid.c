/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:44:05 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:17:47 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_valid(t_info *i)
{
	i->valid.N = 0;
	i->valid.S = 0;
	i->valid.E = 0;
	i->valid.W = 0;
	i->valid.C = 0;
	i->valid.F = 0;
	i->valid.Map = 0;
}

int	check_valid(t_info *i)
{
	if (!(i->valid.N))
		return (0);
	if (!(i->valid.S))
		return (0);
	if (!(i->valid.E))
		return (0);
	if (!(i->valid.W))
		return (0);
	if (!(i->valid.F))
		return (0);
	if (!(i->valid.C))
		return (0);
	if (!(i->valid.Map))
		return (0);
	return (1);
}
