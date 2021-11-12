/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:48:27 by bclarind          #+#    #+#             */
/*   Updated: 2021/11/12 17:52:02 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	add_nl(char **str)
{
	char	*tmp;

	tmp = *str;
	while (*tmp)
		tmp++;
	*tmp = '\n';
	*++tmp = 0;
}

static char	*check_reminder(char **reminder, char **str)
{
	char	*ptr_to_nl;
	char	*tmp;

	ptr_to_nl = NULL;
	if (*reminder)
	{
		if (ft_strchr(*reminder, '\n'))
		{
			ptr_to_nl = ft_strchr(*reminder, '\n');
			*ptr_to_nl = 0;
		 	*str = ft_strdup(*reminder);
			tmp = *reminder;
			*reminder = ft_strdup(++ptr_to_nl);
			free(tmp);
		}
		else
			*str = ft_strdup(*reminder);
	}
	else
		*str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	return (ptr_to_nl);
}

// int	check_file(int fd)
// {
// 	if 
// }

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	char			*str;
	char			*ptr_to_nl;
	int				len_readed_bytes;
	static char		*reminder;

	if (!fd || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len_readed_bytes = 1;
	ptr_to_nl = check_reminder(&reminder, &str);
	while (!ptr_to_nl && len_readed_bytes > 0)
	{
		len_readed_bytes = read(fd, buf, BUFFER_SIZE);
		if (len_readed_bytes < 0)
			return (NULL);
		buf[len_readed_bytes] = 0;
		if (ft_strchr(buf, '\n'))
		{
			ptr_to_nl = ft_strchr(buf, '\n');
			*ptr_to_nl = 0;
			reminder = ft_strdup(++ptr_to_nl);
		}
		str = ft_strjoin(str, buf);
	}
	add_nl(&str);
	return (str);
}
