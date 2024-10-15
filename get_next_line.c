/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarejok <okarejok@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:48:04 by okarejok          #+#    #+#             */
/*   Updated: 2023/12/08 14:48:06 by okarejok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_and_free(char *s1, char *s2)
{
	char	*str;

	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	str = ft_strjoin(s1, s2);
	ft_free(&s1);
	return (str);
}

static char	*update_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buf;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (ft_free(&buffer));
	new_buf = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	if (!new_buf)
		return (ft_free(&buffer));
	i++;
	while (buffer[i])
	{
		new_buf[j++] = buffer[i++];
	}
	free(buffer);
	buffer = NULL;
	return (new_buf);
}

static char	*next_line(char *buffer)
{
	size_t	i;
	char	*next_line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i = i + 1;
	next_line = ft_calloc(i + 1, sizeof(char));
	if (!next_line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		next_line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		next_line[i++] = '\n';
	return (next_line);
}

static char	*read_file(char	*buffer, int fd)
{
	int		bytes;
	char	*temp_buffer;

	temp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_buffer)
		return (ft_free(&buffer));
	bytes = 1;
	while (bytes > 0 && !ft_strchr(temp_buffer, '\n'))
	{
		bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			temp_buffer[bytes] = 0;
			buffer = ft_join_and_free(buffer, temp_buffer);
		}
	}
	free(temp_buffer);
	if (bytes == -1)
		return (ft_free(&buffer));
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && !ft_strchr(buffer, '\n')) || (!buffer))
		buffer = read_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = next_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = update_buffer(buffer);
	return (line);
}
