/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:32:31 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 20:37:20 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long long	ft_strlen(const char *s)
{
	const char	*ptr;

	ptr = s;
	while (*ptr)
		ptr++;
	return (ptr - s);
}

unsigned long long	ft_strlcat(char *restrict dst, const char *restrict sc,
					unsigned long long n)
{
	unsigned long long	i;
	unsigned long long	len_dst;
	unsigned long long	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(sc);
	if (len_dst >= n)
		return (len_src + n);
	i = 0;
	while (len_dst + i < n - 1)
	{
		dst[len_dst + i] = sc[i];
		i++;
	}
	dst[len_dst + i] = 0;
	return (len_src + len_dst);
}
