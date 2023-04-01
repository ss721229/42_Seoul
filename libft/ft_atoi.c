/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:07:30 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/01 10:48:38 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*skip_isspace(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
	return ((char *)str);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		sign;
	char	*only_num;

	num = 0;
	i = 0;
	sign = 1;
	only_num = skip_isspace(str);
	if (only_num[i] == '-' || only_num[i] == '+')
	{
		if (only_num[i] == '-')
			sign = -1;
		i++;
	}
	while (only_num[i] >= '0' && only_num[i] <= '9')
	{
		num *= 10;
		if (sign == 1)
			num += only_num[i] - '0';
		else
			num -= only_num[i] - '0';
		i++;
	}
	return (num);
}
