/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:52:32 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 08:52:27 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *sc, size_t n)
{
	size_t	i;

	i = 0;
	while (sc[i] && i + 1 < n)
	{
		dst[i] = sc[i];
		i++;
	}
	if (n != 0)
		dst[i] = 0;
	return (ft_strlen(sc));
}
