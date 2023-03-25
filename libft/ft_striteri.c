/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:20:29 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 08:50:19 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char const *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len_s;

	len_s = ft_strlen(s);
	i = 0;
	while (i < len_s)
	{
		f(i, (char *)s + i);
		i++;
	}
}
