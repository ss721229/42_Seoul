/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:31:55 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/01 18:01:03 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_ch(char ch, char const *set)
{
	while (*set)
	{
		if (ch == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1) - 1;
	while (start <= end && check_ch(s1[start], set))
		start++;
	while (end >= 0 && check_ch(s1[end], set))
		end--;
	if (end == (size_t) -1)
		str = (char *)malloc(1);
	else
		str = (char *)malloc(end - start + 2);
	if (str == NULL)
		return (0);
	if (end == (size_t) -1)
		str[0] = '\0';
	else
	{
		ft_memcpy(str, s1 + start, end - start + 1);
		str[end - start + 1] = '\0';
	}
	return (str);
}
