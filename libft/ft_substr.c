/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:42:56 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 08:40:52 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
len이 널 포함 길이(?)
아니면 널을 포함하지 않은 길이(?)
널을 안붙여도 되나(?)
일단 널 포함 길이로 짜놓음.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len_s;

	i = 0;
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (0);
	len_s = ft_strlen(s);
	while (i + start < len_s && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
