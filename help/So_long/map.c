/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 19:34:57 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/04/07 19:52:51 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_ret(char *ret, int *comp, int fd)
{	
	while (ret != NULL)
	{
		(*comp)++;
		free(ret);
		ret = get_next_line(fd);
	}
	free (ret);
}

void	addgnltomaps(t_info *i, int comp, int fd)
{
	int	n;

	n = -1;
	while (--comp >= 0)
		i->map.map_s[++n] = get_next_line(fd);
}

void	make_tab(t_info *i)
{
	int		fd;
	int		comp;
	char	*ret;

	comp = 0;
	fd = ft_open(i->map.name_fichier);
	ret = get_next_line(fd);
	count_ret(ret, &comp, fd);
	i->map.map_height = comp;
	close(fd);
	i->map.map_width = m_test_rect(i->map.name_fichier, comp);
	m_verif_map(i, i->map.name_fichier, comp);
	fd = open(i->map.name_fichier, O_RDONLY);
	i->map.map_s = calloc(sizeof(char *), (i->map.map_height + 1));
	addgnltomaps(i, comp, fd);
	m_nbr_ennemi(i);
	m_ft_ferme(i);
	return ;
}

void	m_nbr_ennemi(t_info *i)
{
	int	n;
	int	j;

	n = -1;
	i->map.nbr_ennemi = 0;
	while (++n < i->map.map_height)
	{
		j = -1;
		while (++j < i->map.map_width)
		{
			if (i->map.map_s[n][j] == 'D')
				i->map.nbr_ennemi++;
		}
	}
	i->ennemi = calloc(sizeof(t_player), i->map.nbr_ennemi);
}
