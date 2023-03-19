/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 18:37:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/19 15:53:22 by sanseo           ###   ########.fr       */
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

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
	while (i + len_ndl - 1 < n && str1[i])
	{
		if (str1[i] == str2[0])
			if (!ft_strncmp(str1 + i, str2, len_ndl))
				return (str1 + i);
		i++;
	}
	return (0);
}
