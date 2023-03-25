/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:31:51 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 10:07:41 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len_s1;

	len_s1 = ft_strlen(s1);
	str = (char *)malloc(len_s1 + 1);
	if (str == NULL)
		return (0);
	ft_memcpy(str, s1, len_s1);
	str[len_s1] = '\0';
	return (str);
}
