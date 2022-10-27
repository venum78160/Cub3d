/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/15 20:20:24 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
# define CUB_3D

/* ************************* INCLUDES ************************* */
# include "../Libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_opengl.h"
# include "../minilibx/mlx_png.h"
# include <stdio.h>
# include <fcntl.h>

/* ************************ STRUCTURES ************************ */

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		player;
	char	*name_fichier;
}	t_map;

typedef struct s_player {
	int		x;
	int		y;
	int		neg;
}	t_player;

typedef struct s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bppixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_info {
	t_data			st_img;
	t_map			i_map;
	char			**map;
	unsigned int	color;
}	t_info;

/* *************************** INIT ************************** */


/* ************************** ERREUR ************************* */
void	msg_exit(char *string);

#endif