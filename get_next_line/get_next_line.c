/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 13:27:17 by sanseo            #+#    #+#             */
/*   Updated: 2023/07/22 16:19:21 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*restore_total(char *total)
{
	char	*new_total;
	char	*ptr;
	int		len;

	ptr = ft_strchr(total, '\n');
	if (!ptr)
	{
		new_total = NULL;
		return (ft_free(&total));
	}
	else
		len = (ptr - total) + 1;
	if (!total[len])
		return (ft_free(&total));
	new_total = ft_substr(total, len, ft_strlen(total) - len);
	ft_free(&total);
	if (!new_total)
		return (NULL);
	return (new_total);
}

char	*get_new_line(char *total)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(total, '\n');
	len = (ptr - total) + 1;
	line = ft_substr(total, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_buf(int fd, char *total)
{
	int		flag;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(&total));
	buf[0] = '\0';
	flag = 1;
	while (flag > 0 && !ft_strchr(buf, '\n'))
	{
		flag = read (fd, buf, BUFFER_SIZE);
		if (flag > 0)
		{
			buf[flag] = '\0';
			total = ft_strjoin(total, buf);
		}
	}
	free(buf);
	if (flag == -1)
		return (ft_free(&total));
	return (total);
}

char	*get_next_line(int fd)
{
	static char	*total;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((total && !ft_strchr(total, '\n')) || !total)
		total = read_buf(fd, total);
	if (!total)
		return (NULL);
	line = get_new_line(total);
	if (!line)
		return (ft_free(&total));
	total = restore_total(total);
	return (line);
}
