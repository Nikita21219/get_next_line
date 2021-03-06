/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:48:27 by bclarind          #+#    #+#             */
/*   Updated: 2021/11/15 16:22:17 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	add_nl(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp)
		tmp++;
	*tmp = '\n';
	*++tmp = 0;
}

static void	*free_str(char *str)
{
	free(str);
	return (NULL);
}

static char	*get_str(char *buf, char *str)
{
	int			i;
	char		*ptr_to_nl;

	ptr_to_nl = ft_strchr(buf, '\n');
	*ptr_to_nl++ = 0;
	str = ft_strjoin(str, buf);
	if (!str)
		return (NULL);
	i = 0;
	while (*ptr_to_nl)
		buf[i++] = *ptr_to_nl++;
	buf[i] = 0;
	add_nl(&str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*str;
	int			len_readed_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	len_readed_bytes = 1;
	str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	if (ft_strchr(buf[fd], '\n'))
		return (get_str(buf[fd], str));
	str = ft_strjoin(str, buf[fd]);
	while (len_readed_bytes)
	{
		len_readed_bytes = read(fd, buf[fd], BUFFER_SIZE);
		if (len_readed_bytes <= 0 && !*str)
			return (free_str(str));
		buf[fd][len_readed_bytes] = 0;
		if (ft_strchr(buf[fd], '\n'))
			return (get_str(buf[fd], str));
		str = ft_strjoin(str, buf[fd]);
	}
	return (str);
}
