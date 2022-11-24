/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:42:36 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:26:56 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int    handle_spawn_EW(char c, t_info *infos)
{
    if (c == 'E')
    {
        infos->pla.dirx = 0;
        infos->pla.diry = 1;
        infos->pla.plane_x = FOVY;
        infos->pla.plane_y = 0;
        return (1);
    }
    if (c == 'W')
    {
        infos->pla.dirx = 0;
        infos->pla.diry = -1;
        infos->pla.plane_x = -1 * FOVY;
        infos->pla.plane_y = 0;
        return (1);
    }
    return (0);
}

int try_set_spawn_point(char c, t_info *infos)
{
    if (c == 'N')
    {
        infos->pla.dirx = -1;
        infos->pla.diry = 0;
        infos->pla.plane_x = 0;
        infos->pla.plane_y = FOVY;
        return (1);
    }
    if (c == 'S')
    {
        infos->pla.dirx = 1;
        infos->pla.diry = 0;
        infos->pla.plane_x = 0;
        infos->pla.plane_y = -1 * FOVY;
        return (1);
    }
    return (handle_spawn_EW(c, infos));
}

void    handle_spawn_error(char **map, t_info *infos)
{
    free_map(map);
    free_texture(infos);
    ft_error("Error:\nmore than 1 spawn.\n", 0);
}

int	set_spawn(char **map, t_info *infos)
{
	int	i;
	int	j;
	int	spawn_amount;

	i = 0;
	spawn_amount = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (try_set_spawn_point(map[i][j], infos))
			{
				spawn_amount++;
				if (spawn_amount > 1)
                    handle_spawn_error(map, infos);
				infos->pla.pl_y = (double)j + 0.5;
				infos->pla.pl_x = (double)i + 0.5;
			}
			j++;
		}
		i++;
	}
	return (0);
}
