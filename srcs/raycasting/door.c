/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:49:28 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/23 17:54:00 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_invert(int x, int y, t_info *info)
{
	if (info->map[x][y] == 'P')
		return ('O');
	return ('P');
}

int	action_door(int x, int y, t_info *info)
{
	info->map[x][y] = get_invert(x, y, info);
	info->text.count = 0;
	return (1);
}

int	is_door(char c)
{
	if (c == 'O')
		return (1);
	if (c == 'P')
		return (1);
	return (0);
}

int	no_hitbox(char c)
{
	if (c == '1')
		return (0);
	if (c == 'P')
		return (0);
	return (1);
}

void	action_door_around(int x, int y, t_info *info)
{
	if (is_door(info->map[x + 1][y]))
		action_door(x + 1, y, info);
	if (is_door(info->map[x + 1][y + 1]))
		action_door(x + 1, y + 1, info);
	if (is_door(info->map[x + 1][y - 1]))
		action_door(x + 1, y - 1, info);
	if (is_door(info->map[x][y + 1]))
		action_door(x, y + 1, info);
	if (is_door(info->map[x][y - 1]))
		action_door(x, y - 1, info);
	if (is_door(info->map[x - 1][y - 1]))
		action_door(x - 1, y - 1, info);
	if (is_door(info->map[x - 1][y]))
		action_door(x - 1, y, info);
	if (is_door(info->map[x - 1][y + 1]))
		action_door(x - 1, y + 1, info);
}
