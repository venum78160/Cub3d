/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:41:47 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/22 21:25:32 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	add_bonus_path(t_info *info)
{
	close(ft_open("./texture/jungle/door_iron_lower.xpm"));
	check_for_id("P ./texture/jungle/door_iron_lower.xpm", info);
	return (1);
}

void	handle_bonus(t_info *info, int type, char *path)
{
	int	x;
	int	y;

	if (type == 4)
	{
		info->text.text_P = ft_calloc(sizeof(t_data), 1);
		info->text.text_P->img = mlx_xpm_file_to_image(info->mlx, path, &x, &y);
		info->text.text_P->addr = mlx_get_data_addr(info->text.text_P->img,
				&info->text.text_P->bppixel,
				&info->text.text_P->line_length,
				&info->text.text_P->endian);
	}
}
