/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:42:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 21:08:17 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

/*
len이 널 포함 길이(?)
아니면 널을 포함하지 않은 길이(?)
널을 안붙여도 되나(?)
일단 널 포함 길이로 짜놓음.
*/

unsigned long long	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

char	*ft_substr(char const *s, unsigned int start, unsigned long long len)
{
	char				*str;
	unsigned int		i;
	unsigned long long	len_s;

	i = 0;
	str = (char *)malloc(len);
	if (str == NULL)
		return (0);
	len_s = ft_strlen(s);
	while (i + start < len_s && i + start < len + start - 1)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
