/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:49:31 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/22 20:49:38 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*remove_newline(char *line)
{
	int		i;
	char	*res;

	i = 0;
	res = ft_calloc(ft_strlen(line), 1);
	while(line[i] && line[i] != '\n')
	{
		res[i] = line[i];
		i++;
	}
	free(line);
	return (res);
}