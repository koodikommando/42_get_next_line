/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okarejok <okarejok@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:48:09 by okarejok          #+#    #+#             */
/*   Updated: 2023/12/08 14:48:10 by okarejok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*aux;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	aux = malloc((len + 1) * sizeof(char));
	if (!aux)
		return (NULL);
	while (s1[i])
	{
		aux[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
		aux[j++] = s2[i++];
	aux[j] = 0;
	return (aux);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	check_max;
	size_t	i;

	check_max = count * size;
	if (size != 0 && count != check_max / size)
		return (NULL);
	if (count != 0 && size != check_max / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	i = 0;
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
