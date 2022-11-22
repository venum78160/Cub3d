/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/11/22 22:52:50 by vl-hotel         ###   ########.fr       */
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
# define SPACE 49
# define SPEED 0.11
# define SPEED_ROT 0.04
# define ARROW_L 123
# define ARROW_R 124
# define LOC_MAP_X 50
# define LOC_MAP_Y 50
# define SIZE_BLOCK_MAP 12
# define NBR_BL_MAP 11
# define SENSIVITY 0.7


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
	char	*name_fichier;
}	t_map;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bppixel;
	int		line_length;
	int		endian;
	char	*color;
}	t_data;

typedef struct s_valid {
	int	N;
	int S;
	int W;
	int E;
	int F;
	int C;
	int Map;
}	t_valid;

typedef struct s_rect {
	int	x;
	int	m_x;
	int	y;
	int	m_y;
}	t_rect;

typedef struct s_texture
{
	t_data	*text_N;
	t_data	*text_S;
	t_data	*text_E;
	t_data	*text_W;
	t_data	*text_P;
	t_data	*door_close;
	t_data	*door_1;
	t_data	*door_2;
	t_data	*door_3;
	t_data	*door_4;
	t_data	*door_5;
	double	wallx;
	int		texX;
	int		texY;
	double	step;
	double	textpos;
	int		color;
	int		count;
}	t_text;

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
	int			hit_door;
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

typedef struct s_info {
	t_data			st_img;
	t_valid			valid;
	t_map			i_map;
	t_pla			pla;
	t_text			text;
	char			**map;
	unsigned int	floor_c;
	unsigned int	ceiling_c;
	void	*mlx;
	void	*mlx_win;
}	t_info;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	print_text(t_info *i, int x);
int		render(t_info *i);
void	print_line_wall(t_info *i, int x);
void	init_ray(t_info *i, int x);
void	step(t_info *i);
void	dda(t_info *i);
void 	parsing(t_info *i);
int		keyevent(int keyword, t_info *i);
int		ft_quit(t_info *i);
void	get_color(t_data *data, int x, int y);
char	find_wall(t_info *i);
void	put_pixel_image(t_info *i, t_data *data, int x, int y);
void	text_increaser(t_info *i, int boucle);
void	backgroud(t_info *i);
void	right_turn(t_info *i);
void	left_turn(t_info *i);
int		ft_strlen2star(char **str);

/* *************************** PARSING *********************** */

void 	parsing_v2(t_info *i, char* src);
int		ft_open(char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_error(char *err, int type);
char	*ft_gnljoin(char *s1, char *s2);
char	*get_extension(char *src);
char	*get_next_line(int fd);


/* *************************** INIT ************************** */
void	text_init(t_info *i);

/* ************************** MINIMAP ************************* */
void	minimap(t_info	*i);
void	ml_case(t_info *i, void (*fonction)());
void	ml_rect(t_info info, t_rect rect, int color);
void	ml_fond_case(int x, int y, t_info *i);

/* ************************** ERREUR ************************* */
void	msg_exit(char *string);
int		free_all(t_info *info);

void	text_door(t_info *i, int x, int y);

#endif