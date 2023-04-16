/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 12:02:21 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/16 17:49:58 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>

int	ft_printf(const char *format, ...);

int	ft_printf_char(va_list ap);
int	ft_printf_string(va_list ap);
int	ft_printf_int(va_list ap);
int	ft_printf_addr(va_list ap);
int	ft_printf_unsigned_int(va_list ap);
int	ft_printf_lower_hex(va_list ap);
int	ft_printf_upper_hex(va_list ap);
int	ft_printf_percent(void);

int	check_and_put_zero(int *len);

#endif