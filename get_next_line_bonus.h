/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 18:24:59 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/03/10 20:19:11 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

# if BUFFER_SIZE >= INT_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 5
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