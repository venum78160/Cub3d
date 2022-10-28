/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:26:08 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/15 15:27:15 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx/mlx.h"
# include "minilibx/mlx_opengl.h"
# include "minilibx/mlx_png.h"
# include <stdio.h>
# include <fcntl.h>

//structure

typedef struct s_map
{
	int		map_width;
	int		map_height;
	int		nb_m;
	void	*coin;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*coin5;
	void	*coin6;
	void	*coin7;
	void	*coin8;
	void	*coin9;
	void	*tree;
	void	*over;
	void	*gr;
	void	*hero;
	void	*portail1;
	void	*portail2;
	void	*portail3;
	void	*portail4;
	void	*gg;
	void	*mob;
	char	**map_s;
	int		coll;
	int		exit;
	int		player;
	int		nbr_ennemi;
	char	*name_fichier;
}	t_map;

typedef struct s_player {
	int		x;
	int		y;
	int		neg;
}	t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bppixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_rect {
	int	x;
	int	m_x;
	int	y;
	int	m_y;
}	t_rect;

typedef struct s_info {
	t_data			st_img;
	void			*mlx;
	void			*mlx_win;
	int				gg;
	t_player		player;
	t_player		*ennemi;
	t_map			map;
	int				dead;
	unsigned int	color;
}	t_info;

//prototype

void			msg_exit(char *string);
unsigned int	get_mlx_pixel(t_data *data, int x, int y);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				key_hook(int keycode, void *vars);
void			make_struct(t_info *info, char *fichier);
void			ml_rect(t_info info, t_rect rect, int color);
int				render(t_info *ml);
int				move_up(t_info *info);
int				move_down(t_info *info);
int				move_left(t_info *info);
int				move_right(t_info *info);
void			make_tab(t_info *info);
int				ft_open(char *fichier);
int				m_test_rect(char *fichier, int comp);
void			m_verif_map(t_info *info, char *fichier, int comp);
int				ft_test(char c, char *sep);
void			m_verif_cat(t_info *info, char *ligne, int comp, int fd);
void			verif_pec(t_info info);
void			m_ft_ferme(t_info *info);
void			ft_del_maps(t_info *info, char *string);
void			m_init(t_info *info, char c, int x, int y);
void			m_nbr_ennemi(t_info *info);
void			ml_case(t_info *info, void (*fonction)());
void			ml_fond_case(int x, int y, t_info *info);
void			ml_sprite_case(int x, int y, t_info *info);
void			display_coin(t_info *info, int x, int y);
void			display_portal(t_info *info, int x, int y);
void			move_mob(t_info *info);
void			verif_dead(t_info *info);
void			make_struct2(t_info *i);
void			sprite_grasstree(t_info *i, int x, int y);
void			sprite_grass(t_info *i, int x, int y);
void			rendercadre(t_info *i);
void			display_mob(t_info *i, t_rect va);
int				ft_quit(t_info *i);

#endif