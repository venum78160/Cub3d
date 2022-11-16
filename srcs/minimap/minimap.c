/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:07:49 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/16 00:11:45 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	minimap(t_info	*i)
// {
	
// }

// void	ml_case(t_info *i, void (*fonction)())
// {
// 	int	x;
// 	int	y;

// 	y = LOC_MAP_Y;
// 	while (y < (LOC_MAP_Y + SIZE_BLOCK_MAP * NBR_BL_MAP))
// 	{
// 		x = LOC_MAP_X;
// 		while (x < (LOC_MAP_X + SIZE_BLOCK_MAP * NBR_BL_MAP))
// 		{
// 			fonction(x, y, i);
// 			x += SIZE_BLOCK_MAP;
// 		}
// 		y += SIZE_BLOCK_MAP;
// 	}
// }

// void	ml_fond_case(int x, int y, t_info *i)
// {
// 	int	ind_x;
// 	int	ind_y;

// 	ind_x = i->pla.x - 3 + ((x - 126) / 64);
// 	ind_y = i->pla.y - 3 + ((y - 126) / 64);
// 	if (ind_x < 0 || ind_y < 0)
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (ind_x >= i->map.map_width || ind_y >= i->map.map_height)
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (ind_x == i->pla.x && ind_y == i->pla.y)
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (i->map.map_s[ind_y][ind_x] == '1')
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (i->map.map_s[ind_y][ind_x] == '0')
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (i->map.map_s[ind_y][ind_x] == 'C')
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (i->map.map_s[ind_y][ind_x] == 'D')
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// 	else if (i->map.map_s[ind_y][ind_x] == 'E')
// 		ml_rect(*i, (t_rect){x, x + 64, y, y + 64}, 0x00499848);
// }