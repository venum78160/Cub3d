/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/05 22:50:58 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
# define CUB_3D

# define WIDTH 1300
# define HEIGHT 690
# define FOVY 0.66
# define TEXT_SIZE 64
# define ESC 53
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define SPEED 0.11
# define SPEED_ROT 0.04
# define ARROW_L 123
# define ARROW_R 124


/* ************************* INCLUDES ************************* */
# include "../Libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_opengl.h"
# include "../minilibx/mlx_png.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

/* ************************ STRUCTURES ************************ */

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		pla;
	char	*name_fichier;
}	t_map;

typedef struct s_pla {
	double		pl_x;
	double		pl_y;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		delta_X;
	double		delta_Y;
	int			hit;
	int			step_x;
	int			step_y;
	int			side;
	double		side_disX;
	double		side_disY;
	double		dist_wall;
	int			line_h;
	int			draw_start;
	int			draw_end;
	double		time;
	double		oldtime;
}	t_pla;

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
	t_pla			pla;
	char			**map;
	unsigned int	floor_c;
	unsigned int	ceiling_c;
}	t_info;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_text(t_info *i, int x);
int		render(t_info *i);
void	print_line_wall(int x, t_info *i, int color);
void	init_ray(t_info *i, int x);
void	step(t_info *i);
void	dda(t_info *i);
void 	parsing(t_info *i);
int		keyevent(int keyword, t_info *i);
int		ft_quit(t_info *i);
/* *************************** INIT ************************** */


/* ************************** ERREUR ************************* */
void	msg_exit(char *string);

#endif