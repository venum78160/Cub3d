/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:44:05 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:45:03 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_valid(t_info *i)
{
	i->valid.n = 0;
	i->valid.s = 0;
	i->valid.e = 0;
	i->valid.w = 0;
	i->valid.c = 0;
	i->valid.f = 0;
	i->valid.map = 0;
}

int	check_valid(t_info *i)
{
	if (!(i->valid.n))
		return (0);
	if (!(i->valid.s))
		return (0);
	if (!(i->valid.e))
		return (0);
	if (!(i->valid.w))
		return (0);
	if (!(i->valid.f))
		return (0);
	if (!(i->valid.c))
		return (0);
	if (!(i->valid.map))
		return (0);
	return (1);
}
