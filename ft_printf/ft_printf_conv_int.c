/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:37:54 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/09 13:59:50 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_unsigned_nbr(unsigned int arg)
{
	char	val[10];
	int		index;
	int		len;

	index = 0;
	while (arg > 0)
	{
		val[index] = arg % 10 + '0';
		arg /= 10;
		index++;
	}
	len = index;
	while (--index >= 0)
		if (write(1, &val[index], 1) == -1)
			return (-1);
	return (len);
}

int	ft_printf_int(va_list ap)
{
	int	arg;
	int	len;

	arg = va_arg(ap, int);
	if (arg < 0)
	{
		if (write(1, &"-", 1) == -1)
			return (-1);
		arg *= -1;
		len = ft_put_unsigned_nbr(arg) + 1;
	}
	else
		len = ft_put_unsigned_nbr(arg);
	if (check_and_put_zero(&len) == -1)
		return (-1);
	return (len);
}

int	ft_printf_unsigned_int(va_list ap)
{
	unsigned int	arg;
	int				len;

	arg = va_arg(ap, unsigned int);
	len = ft_put_unsigned_nbr(arg);
	if (check_and_put_zero(&len) == -1)
		return (-1);
	return (len);
}
