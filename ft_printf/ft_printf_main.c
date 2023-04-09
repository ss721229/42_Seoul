/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:01:55 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/09 13:58:03 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_type(va_list ap, const char *format)
{
	int	err_or_len;

	err_or_len = 0;
	if (*format == 'c')
		err_or_len = ft_printf_char(ap);
	else if (*format == 's')
		err_or_len = ft_printf_string(ap);
	else if (*format == 'd' || *format == 'i')
		err_or_len = ft_printf_int(ap);
	else if (*format == 'p')
		err_or_len = ft_printf_addr(ap);
	else if (*format == 'u')
		err_or_len = ft_printf_unsigned_int(ap);
	else if (*format == 'x')
		err_or_len = ft_printf_lower_hex(ap);
	else if (*format == 'X')
		err_or_len = ft_printf_upper_hex(ap);
	else if (*format == '%')
		err_or_len = ft_printf_percent();
	else
		return (-1);
	return (err_or_len);
}

int	ft_printf(const char *format, ...)
{
	int		total_len;
	va_list	ap;
	int		err_or_len;

	total_len = 0;
	va_start (ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (write(1, format, 1) == -1)
				return (-1);
			total_len++;
		}
		else
		{
			err_or_len = ft_printf_type(ap, ++format);
			if (err_or_len == -1)
				return (-1);
			total_len += err_or_len;
		}
		format++;
	}
	va_end (ap);
	return (total_len);
}
