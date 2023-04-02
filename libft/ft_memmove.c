/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:27:06 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/01 18:42:05 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sc;
	size_t		i;

	dest = (char *)dst;
	sc = (const char *)src;
	if (dest < sc)
	{
		i = 0;
		while (i < len)
		{
			dest[i] = sc[i];
			i++;
		}
	}
	else if (dest > sc)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = sc[i];
		}
	}
	return (dst);
}
