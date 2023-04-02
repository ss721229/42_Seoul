/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:37:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/01 18:59:59 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_ndl;

	len_ndl = ft_strlen(needle);
	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + len_ndl - 1 < len)
	{
		if (haystack[i] == needle[0])
			if (!ft_strncmp(haystack + i, needle, len_ndl))
				return ((char *)haystack + i);
		i++;
	}
	return (0);
}
