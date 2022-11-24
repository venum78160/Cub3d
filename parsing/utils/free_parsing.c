/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:38:20 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:27:47 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

int	free_texture(t_info *info)
{
	if (info->valid.S)
		free(info->text.text_s);
	if (info->valid.N)
		free(info->text.text_n);
	if (info->valid.W)
		free(info->text.text_w);
	if (info->valid.E)
		free(info->text.text_e);
	return (0);
}

int	free_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
	return (0);
}
