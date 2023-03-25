/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:04:51 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/26 00:29:36 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*elem;
	t_list	*head;

	if (lst == NULL)
		return (0);
	p = lst;
	elem = NULL;
	while (p)
	{
		elem = ft_lstnew(f(p->content));
		if (elem == NULL)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		ft_lstadd_back(&head, elem);
		p = p->next;
	}
	return (head);
}
