/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 19:17:49 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/14 18:48:17 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	m_test_rect(char *fichier, int comp)
{
	size_t	x;
	int		fd;
	char	*ret;

	fd = ft_open(fichier);
	ret = get_next_line(fd);
	x = ft_strlen(ret);
	while (--comp >= 1)
	{
		free (ret);
		ret = get_next_line(fd);
		if (ft_strlen(ret) != x)
			msg_exit("la map n'est pas une map rectangulaire");
	}
	free(ret);
	close(fd);
	return (x);
}

void	m_verif_cat(t_info *i, char *ligne, int comp, int fd)
{
	int	j;

	while (--comp >= 0)
	{
		ligne = get_next_line(fd);
		j = -1;
		while (ligne[++j])
		{
			if (ligne[j] == 'C')
				i->map.coll++;
			else if (ligne[j] == 'P')
				i->map.player++;
			else if (ligne[j] == 'E')
				i->map.exit++;
			else if (ft_test(ligne[j], "01CPED") == 0)
			{
				free(ligne);
				msg_exit("Mauvais caractere sur la carte");
			}
		}
		free(ligne);
	}
	close(fd);
}

void	m_verif_pec(t_info i)
{
	if (i.map.coll < 1)
		msg_exit("pas assez de collectible");
	if (i.map.exit < 1)
		msg_exit("pas assez d'exit");
	if (i.map.player != 1)
		msg_exit("pas le bon nombre de player");
}

void	m_verif_map(t_info *i, char *fichier, int comp)
{
	int		fd;
	char	*ligne;

	fd = ft_open(fichier);
	ligne = NULL;
	m_verif_cat(i, ligne, comp, fd);
	m_verif_pec(*i);
}

void	m_ft_ferme(t_info *i)
{
	int	n;
	int	j;

	n = -1;
	while (++n < i->map.map_height)
	{
		if (i->map.map_s[n][0] != '1'
			|| i->map.map_s[n][i->map.map_width - 1] != '1')
			ft_del_maps(i, "mauvaise bordure");
		j = -1;
		while (++j < i->map.map_width)
		{
			if (n == 0 && (i->map.map_s[n][j] != '1'))
				ft_del_maps(i, "ligne 1 pas que des 1");
			else if (n == i->map.map_height - 1 && i->map.map_s[n][j] != '1')
				ft_del_maps(i, "derniere ligne pas que des 1");
			m_init(i, i->map.map_s[n][j], j, n);
		}
	}
}
