/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42seoul.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:28:58 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/16 09:39:26 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, const void *src, unsigned long long n)
{
	char *dst;
	const char *sc;

	dst = (char *)dest;
	sc = (const char *)src;
	while(n--)
		*dst++ = *sc++;
	return (dest);
}