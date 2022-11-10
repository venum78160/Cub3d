/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:31:20 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/10 19:40:00 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int ft_open(char *src)
{
    int fd;
    
	fd = open(src, O_DIRECTORY | O_WRONLY, 0644);
	if (fd > 0)
	{
		printf("%s is a directory\n", src);
		exit ();
	}
	fd = open(src, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", src);
        exit ();
	}
    return (fd);
}