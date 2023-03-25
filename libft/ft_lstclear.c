/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:40:58 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/25 23:33:45 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*pnext;

	if (*lst == NULL)
		return ;
	p = *lst;
	pnext = *lst;
	while (pnext)
	{
		pnext = p->next;
		ft_lstdelone(p, del);
		p = pnext;
	}
	*lst = NULL;
}
