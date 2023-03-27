/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42seoul.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 16:40:10 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/27 19:36:44 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recur_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n >= 10)
		recur_putnbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, &"-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, &"-", 1);
		n *= -1;
	}
	recur_putnbr_fd(n, fd);
}
