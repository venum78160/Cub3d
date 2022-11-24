/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:47:39 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 18:02:11 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	char_checker(char c, int j)
{
	if (j < 0 || c == '\0')
		return (1);
	if (c == '1' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	spot_checker(char **map, int i, int j)
{
	if (!char_checker(map[i][j + 1], j + 1))
		return (0);
	if (!char_checker(map[i][j - 1], j - 1))
		return (0);
	if (!char_checker(map[i + 1][j], j))
		return (0);
	if (!char_checker(map[i + 1][j + 1], j + 1))
		return (0);
	if (!char_checker(map[i + 1][j - 1], j - 1))
		return (0);
	if (!char_checker(map[i - 1][j], j))
		return (0);
	if (!char_checker(map[i - 1][j + 1], j + 1))
		return (0);
	if (!char_checker(map[i - 1][j - 1], j - 1))
		return (0);
	return (1);
}

int	wall_line_checker(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] == ' ' || map[i][j] == '\n' || map[i][j] == '\0')
		{
			if (!spot_checker(map, i, j))
				return (0);
		}
		else if (!j)
		{
			if (map[i][j] != '1')
				return (0);
		}
		j++;
	}
	return (1);
}

void	wall_check(char **map, t_info *info)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!i)
			wall_line_checker_tb(map[i], map, info);
		else if (!map[i + 1])
			wall_line_checker_tb(map[i], map, info);
		else
		{
			if (!wall_line_checker(map, i))
			{
				free(map);
				free_texture(info);
				ft_error("Error:\nmap must be closed.\n", 0);
			}
		}
		i++;
	}
}
