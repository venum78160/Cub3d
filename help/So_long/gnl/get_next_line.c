/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:28:36 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/14 19:00:33 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *buffer, char *add)
{
	int		i;
	char	*new;
	int		t;
	int		j;

	t = ft_strlen_gnl(buffer) + ft_strlen_gnl(add) + 1;
	new = malloc(sizeof(char) * t);
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	while (buffer[++i])
		new[i] = buffer[i];
	while (add[j])
		new[i++] = add[j++];
	new[i] = '\0';
	free (buffer);
	return (new);
}

char	*ft_reset_buffer(char *buffer, int sizeline)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	line = malloc(sizeof(char) * (ft_strlen_gnl(buffer) - sizeline + 1));
	if (!line)
		return (NULL);
	while (i < sizeline)
		i++;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free (buffer);
	return (line);
}

char	*ft_add_buffer(int fd, char *buffer)
{
	char	*add;
	int		tete;

	add = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!add)
		return (NULL);
	tete = 1;
	while (!ft_strchr_gnl(buffer, '\n') && tete != 0)
	{
		tete = read(fd, add, BUFFER_SIZE);
		if (tete < 0)
		{
			free (add);
			free (buffer);
			return (NULL);
		}
		add[tete] = '\0';
		buffer = ft_strjoin_gnl(buffer, add);
	}
	free (add);
	return (buffer);
}

char	*new_line(char *buffer)
{
	int		newbuf;
	char	*line;

	if (buffer == NULL)
		return (NULL);
	if (ft_strchr_gnl(buffer, '\n') == NULL)
		newbuf = 0;
	else
		newbuf = ft_strlen_gnl(ft_strchr_gnl(buffer, '\n')) - 1;
	line = malloc(sizeof(char) * (ft_strlen_gnl(buffer) - newbuf) + 1);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(line, buffer, (ft_strlen_gnl(buffer) - newbuf) + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup_gnl("");
	buffer = ft_add_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	buffer = ft_reset_buffer(buffer, ft_strlen_gnl(line));
	if (line[0] == '\0')
	{
		free (line);
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	line = new_line_after(line);
	return (line);
}
