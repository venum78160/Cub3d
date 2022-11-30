/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgoudin <mgoudin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 20:43:36 by mgoudin           #+#    #+#             */
/*   Updated: 2022/11/30 16:48:02 by mgoudin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

char	*get_id(char *line)
{
	char	*id;
	int		i;

	id = ft_calloc(3, 1);
	i = 0;
	while (i < 2)
	{
		id[i] = line[i];
		i++;
	}
	id[i] = '\0';
	return (id);
}

int	check_for_id(char *line, t_info *info)
{
	char	*id;
	int		res;

	res = 0;
	id = get_id(line);
	if (!ft_strcmp(id, "NO"))
		res = handle_path(line, 0, info, id);
	if (!ft_strcmp(id, "SO"))
		res = handle_path(line, 1, info, id);
	if (!ft_strcmp(id, "WE"))
		res = handle_path(line, 2, info, id);
	if (!ft_strcmp(id, "EA"))
		res = handle_path(line, 3, info, id);
	if (line[0] && line[0] == 'P')
		res = handle_path(line, 4, info, id);
	if (line[0] && line[0] == 'F')
		res = handle_color(line, 0, info, id);
	if (line[0] && line[0] == 'C')
		res = handle_color(line, 1, info, id);
	free(id);
	return (res);
}
