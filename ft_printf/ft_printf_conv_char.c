/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:38:23 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/09 13:55:48 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(va_list ap)
{
	char	arg;

	arg = va_arg(ap, int);
	if (write(1, &arg, 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_percent(void)
{
	if (write(1, &"%", 1) == -1)
		return (-1);
	return (1);
}

int	ft_printf_string(va_list ap)
{
	int		len;
	char	*str;

	len = 0;
	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	while (str[len])
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}
