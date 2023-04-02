/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:07:30 by sanseo            #+#    #+#             */
/*   Updated: 2023/04/02 16:42:51 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*skip_isspace(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
			str++;
	return ((char *)str);
}

static char	*check_sign(const char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			*sign = -1;
	}
	return ((char *)str);
}

static char	*skip_zero(const char *str)
{
	while (*str == '0')
		str++;
	return ((char *)str);
}

static int	check_over_range(unsigned long long int num, int sign)
{
	if (num > 9223372036854775807)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	unsigned long long int	num;
	int						i;
	int						sign;

	num = 0;
	i = 0;
	sign = 1;
	str = skip_isspace(str);
	str = check_sign(str, &sign);
	str = skip_zero(str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if ((i >= 20 && sign == 1) || check_over_range(num, sign) == -1)
		return (-1);
	else if ((i >= 20 && sign == -1) || check_over_range(num, sign) == 0)
		return (0);
	else
		return (sign * num);
}
