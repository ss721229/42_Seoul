/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:32:31 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 08:52:18 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *sc, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(sc);
	if (len_dst >= n)
		return (len_src + n);
	i = 0;
	while (len_dst + i < n - 1)
	{
		dst[len_dst + i] = sc[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}
