/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:41:41 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/25 01:16:36 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_extension_len(char *src)
{
	int	len;
	int	ext_len;

	len = ft_strlen(src) - 1;
	ext_len = len;
	while (src[ext_len] && src[ext_len] != '.')
		ext_len--;
	return (len - ext_len);
}

char	*get_extension(char *src)
{
	int		len;
	int		ext_len;
	char	*res;
	int		i;

	len = ft_strlen(src) - 1;
	ext_len = get_extension_len(src);
	res = ft_calloc(ext_len + 2, 1);
	i = 0;
	while (src[len - ext_len])
	{
		res[i] = src[len - ext_len];
		i++;
		ext_len--;
	}
	res[i] = '\0';
	return (res);
}
