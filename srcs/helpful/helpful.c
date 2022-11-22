/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpful.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 20:01:38 by lhotellier        #+#    #+#             */
/*   Updated: 2022/11/22 16:21:32 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	msg_exit(char *string)
{
	printf("❌ ");
	ft_putstr_fd(string, 2);
	exit(1);
}

int	ft_quit(t_info *i)
{
	mlx_destroy_window(i->mlx, i->mlx_win);
	free_all(i);
	exit(1);
	return (EXIT_SUCCESS);
}