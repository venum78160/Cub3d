/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_extension.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:41:41 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/10 20:29:32 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int ft_strlen(char *src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

int	get_extension_len(char *src)
{
	int	len;
	int	ext_len;

	len = ft_strlen(src) - 1;
	ext_len = len;
	while (src[ext_len] && src[ext_len] != '.')
		ext_len--;
	return (len - ext_len + 1);
}

int get_extension(char *src)
{
	int		len;
	int		ext_len;
	char	*res;

	len = ft_strlen(src) - 1;
	ext_len = get_extension_len(src);
	res = ft_calloc(ext_len, 1);
	while(src[i])
	{
		
	}
	return (res);
}