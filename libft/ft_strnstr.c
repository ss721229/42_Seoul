/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:37:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 11:21:11 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystk, const char *ndl, size_t n)
{
	size_t	i;
	size_t	len_ndl;
	char	*str1;
	char	*str2;

	str1 = (char *)haystk;
	str2 = (char *)ndl;
	len_ndl = ft_strlen(ndl);
	if (*ndl == 0)
		return (str1);
	i = 0;
	while (str1[i] && i + len_ndl - 1 < n)
	{
		if (str1[i] == str2[0])
			if (!ft_strncmp(str1 + i, str2, len_ndl))
				return (str1 + i);
		i++;
	}
	return (0);
}
