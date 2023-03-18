/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 21:28:58 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 20:29:44 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *restrict dest, const void *restrict src,
		unsigned long long n)
{
	char				*dst;
	const char			*sc;
	unsigned long long	i;

	dst = (char *)dest;
	sc = (const char *)src;
	i = 0;
	while (i < n)
	{
		dst[i] = sc[i];
		i++;
	}
	return (dest);
}
