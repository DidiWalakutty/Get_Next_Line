/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: diwalaku <diwalaku@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/03 18:22:16 by diwalaku      #+#    #+#                 */
/*   Updated: 2023/03/12 16:52:50 by diwalaku      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	copy_str(char *dst, char *src)
{
	size_t	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		if (src[x] == '\n')
			return ;
		x++;
	}
}

char	*ft_strjoin(char *line, char *buffer)
{
	size_t	len_l;
	size_t	len_b;
	char	*new;

	len_l = find_length(line);
	len_b = find_length(buffer);
	new = ft_calloc((len_l + len_b + 1), sizeof(char));
	if (!new)
		return (free(line), NULL);
	copy_str(new, line);
	copy_str(&new[len_l], buffer);
	free(line);
	return (new);
}

char	*read_and_join(int fd, char *buffer, char *line)
{
	ssize_t		read_bytes;

	read_bytes = 1;
	if (buffer[0] != '\0')
	{
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	while (!find_newline(buffer) && read_bytes != 0)
	{	
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			buffer[0] = '\0';
			return (free(line), NULL);
		}
		buffer[read_bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	line = ft_calloc(1, sizeof(char));
	if (!line)
		return (NULL);
	line = read_and_join(fd, buffer[fd], line);
	if (!line)
		return (NULL);
	if (buffer[fd][0] != '\0')
		manage_buffer(buffer[fd], find_newline(buffer[fd]));
	if (find_length(line) == 0)
		return (free(line), NULL);
	return (line);
}
