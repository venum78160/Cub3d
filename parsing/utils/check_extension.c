/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:49:07 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/22 21:26:30 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_extension(char *src, char *type)
{
	char	*extension;

	extension = get_extension(src);
	if (ft_strcmp(extension, type))
	{
		free(extension);
		return (0);
	}
	free(extension);
	return (1);
}
