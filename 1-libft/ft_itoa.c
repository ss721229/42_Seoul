/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:14:28 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/19 15:59:05 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	find_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_n;
	int		i;
	int		sign;

	len_n = find_int_len(n);
	str = (char *)malloc(len_n + 1);
	if (str == NULL)
		return (0);
	i = len_n - 1;
	sign = 1;
	if (n < 0)
		sign = -1;
	while (i >= 0)
	{
		if (n < 0)
			str[i--] = n % -10 * (-1) + '0';
		else
			str[i--] = n % 10 + '0';
		n /= 10;
	}
	if (sign == -1)
		str[0] = '-';
	str[len_n] = 0;
	return (str);
}
