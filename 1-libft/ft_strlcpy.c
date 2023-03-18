/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:52:32 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 20:38:10 by sanseo           ###   ########.fr       */
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

unsigned long long	ft_strlcpy(char *restrict dst, const char *restrict sc,
					unsigned long long n)
{
	unsigned long long	i;

	i = 0;
	while (sc[i] && i + 1 < n)
	{
		dst[i] = sc[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(sc));
}
