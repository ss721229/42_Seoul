/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:20:46 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/09 14:15:40 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex_addr(unsigned long long arg)
{
	char	ad[16];
	int		index;
	int		len;

	index = 0;
	while (arg > 0)
	{
		if (arg % 16 <= 9)
			ad[index] = arg % 16 + '0';
		else
			ad[index] = arg % 16 + 'a' - 10;
		arg /= 16;
		index++;
	}
	len = index;
	while (--index >= 0)
		if (write(1, &ad[index], 1) == -1)
			return (-1);
	return (len);
}

static int	ft_put_hex_nbr(unsigned int arg, char lower_or_upper)
{
	char	hex[8];
	int		index;
	int		len;

	index = 0;
	while (arg > 0)
	{
		if (arg % 16 <= 9)
			hex[index % 8] = arg % 16 + '0';
		else
			hex[index % 8] = arg % 16 + lower_or_upper - 10;
		arg /= 16;
		index++;
	}
	len = index;
	while (--index >= 0)
		if (write(1, &hex[index], 1) == -1)
			return (-1);
	return (len);
}

int	ft_printf_addr(va_list ap)
{
	unsigned long long	arg;
	int					len;

	if (write(1, &"0x", 2) == -1)
		return (-1);
	arg = (unsigned long long)va_arg(ap, void *);
	len = ft_put_hex_addr(arg);
	if (check_and_put_zero(&len) == -1)
		return (-1);
	len += 2;
	return (len);
}

int	ft_printf_lower_hex(va_list ap)
{
	int	arg;
	int	len;

	arg = va_arg(ap, int);
	len = ft_put_hex_nbr(arg, 'a');
	if (check_and_put_zero(&len) == -1)
		return (-1);
	return (len);
}

int	ft_printf_upper_hex(va_list ap)
{
	int	arg;
	int	len;

	arg = va_arg(ap, int);
	len = ft_put_hex_nbr(arg, 'A');
	if (check_and_put_zero(&len) == -1)
		return (-1);
	return (len);
}
