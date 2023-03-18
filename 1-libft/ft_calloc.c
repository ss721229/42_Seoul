/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:24:35 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 19:31:36 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_calloc(unsigned long long count, unsigned long long size)
{
	char				*mem;
	unsigned long long	i;

	mem = (char *)malloc(count * size);
	if (mem == NULL)
		return (0);
	i = 0;
	while (i < count * size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
