/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:20:29 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/19 16:28:46 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

size_t	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len_s;

	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		f(i, (char *)s + i);
		i++;
	}
}
