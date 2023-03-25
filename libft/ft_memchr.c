/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:51:29 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 11:30:09 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n && (unsigned char)str[i])
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if ((unsigned char)str[i] == (unsigned char)c && !(unsigned char)c)
		return (str + i);
	return (0);
}
