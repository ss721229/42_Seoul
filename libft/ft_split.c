/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 10:57:41 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 08:49:48 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find_word_cnt(char const *s, char c)
{
	size_t	cnt;
	int		flag;

	cnt = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

char	*allo_and_cpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	dest = (char *)malloc(n + 1);
	if (dest == NULL)
		return (0);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

size_t	find_word_len(char const *s, char c)
{
	char	*save;

	save = (char *)s;
	while (*s != c)
		s++;
	return (s - save);
}

void	free_all(char **str, size_t index_str)
{
	size_t	i;

	i = 0;
	while (i < index_str)
		free(str[index_str]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	cnt;
	size_t	len_word;
	size_t	index_str;

	cnt = find_word_cnt(s, c);
	str = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (str == NULL)
		return (0);
	index_str = 0;
	while (index_str < cnt)
	{
		while (*s == c && *s != '\0')
			s++;
		len_word = find_word_len(s, c);
		str[index_str] = allo_and_cpy(str[index_str], s, len_word);
		if (str[index_str++] == NULL)
		{
			free_all(str, index_str - 2);
			return (0);
		}
		s += len_word;
	}
	str[index_str] = 0;
	return (str);
}
