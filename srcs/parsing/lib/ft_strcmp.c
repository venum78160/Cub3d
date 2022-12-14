/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffiliz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:21:48 by ffiliz            #+#    #+#             */
/*   Updated: 2022/06/21 00:22:04 by ffiliz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	cmp_1;
	unsigned char	cmp_2;

	i = 0;
	cmp_1 = (unsigned char)s1[i];
	cmp_2 = (unsigned char)s2[i];
	while ((cmp_1 && cmp_2))
	{
		cmp_1 = (unsigned char)s1[i];
		cmp_2 = (unsigned char)s2[i];
		if (cmp_1 != cmp_2)
		{
			return (cmp_1 - cmp_2);
		}
		i++;
	}
	return (cmp_1 - cmp_2);
}

int	ft_strlen2star(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
