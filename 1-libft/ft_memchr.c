/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:51:29 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/18 19:53:42 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned long long n)
{
	unsigned long long	i;
	char				*str;

	i = 0;
	str = (char *)s;
	while (str[i] && i < n)
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}
