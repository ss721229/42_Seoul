/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:31:51 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 20:09:35 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

unsigned long long	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	*ft_strdup(const char *s1)
{
	char				*str;
	unsigned long long	i;

	i = ft_strlen(s1);
	str = (char *)malloc(i);
	if (str == NULL)
		return (0);
	while (i >= 0)
	{
		str[i] = s1[i];
		i--;
	}
	return (str);
}
