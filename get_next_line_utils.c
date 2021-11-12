/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:16:34 by bclarind          #+#    #+#             */
/*   Updated: 2021/11/12 16:57:21 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (*s++)
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *) s);
	}
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	return (NULL);
}


void	*ft_bzero(void *destination, size_t n)
{
	size_t	i;
	char	*tmp_buf;

	tmp_buf = destination;
	i = 0;
	while (i < n)
	{
		*tmp_buf = '\0';
		tmp_buf++;
		i++;
	}
	return (destination);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(count * size);
	if (mem)
		ft_bzero(mem, count * size);
	else
		return (NULL);
	return (mem);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mem;
	char	*res;
	char	*s1_free;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	mem = ft_calloc(\
		ft_strlen((char *) s1) + ft_strlen((char *) s2) + 2, \
		sizeof(char));
	if (!(mem))
		return (NULL);
	res = mem;
	s1_free = (char *) s1;
	while (*s1)
		*mem++ = *s1++;
	while (*s2)
		*mem++ = *s2++;
	if (s1_free)
		free(s1_free);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*res;
	char	*tmp_str;

	size = ft_strlen((char *) s1);
	res = ft_calloc(size + 1, sizeof(char));
	if (res == NULL)
	{
		free((char *) s1);
		return (NULL);
	}
	tmp_str = res;
	while (*s1)
		*tmp_str++ = *s1++;
	*tmp_str = 0;
	// if (flag)
	// 	free((char *) s1);
	return (res);
}
