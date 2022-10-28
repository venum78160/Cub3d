/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhotellier <lhotellier@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:09:39 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/14 19:00:36 by lhotellier       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# define BUFFER_SIZE 1024

//prototype
char	*get_next_line(int fd);
char	*ft_add_buffer(int fd, char *buffer);
char	*ft_reset_buffer(char *buffer, int sizeline);
char	*ft_strjoin_gnl(char *buffer, char *add);
int		ft_strlen_gnl(const char *str);
size_t	ft_strlcpy_gnl(char *dest, const char *src, unsigned int size);
char	*ft_strdup_gnl(char *src);
char	*ft_strchr_gnl(const char	*string, int searchedChar);
char	*new_line_after(char *buffer);

#endif