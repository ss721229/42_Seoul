/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:37:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/01 14:42:32 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystk, const char *ndl, size_t n)
{
	size_t	i;
	size_t	len_ndl;

	len_ndl = ft_strlen(ndl);
	if (*ndl == 0)
		return ((char *)haystk);
	i = 0;
	while (haystk[i] && i + len_ndl - 1 < n)
	{
		if (haystk[i] == ndl[0])
			if (!ft_strncmp(haystk + i, ndl, len_ndl))
				return ((char *)haystk + i);
		i++;
	}
	return (0);
}
