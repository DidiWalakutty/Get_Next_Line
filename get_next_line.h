/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 21:33:43 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/03/11 00:00:37 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (3)
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

char	*get_next_line(int fd);
char	*read_and_join(int fd, char *buffer, char *line);
size_t	find_length(const char *s);
char	*find_newline(char *s);
size_t	newline_in_buffer(char *buffer);
char	*ft_strjoin(char *line, char *buffer);
void	manage_buffer(char *dst, char *src);
void	copy_str(char *dst, char *src);
void	*ft_calloc(size_t count, size_t size);

#endif