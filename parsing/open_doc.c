/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:31:20 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/24 17:58:27 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_open(char *src)
{
	int	fd;

	fd = open(src, O_DIRECTORY | O_WRONLY, 0644);
	if (fd > 0)
		ft_error("Error:\nFile is a directory\n", 0);
	fd = open(src, O_RDONLY, 0644);
	if (fd == -1)
		ft_error("Error:\nNo such file or directory\n", 0);
	return (fd);
}
