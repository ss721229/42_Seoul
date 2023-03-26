/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanseo <sanseo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:04:51 by sanseo            #+#    #+#             */
/*   Updated: 2023/03/26 14:22:08 by sanseo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*elem;
	t_list	*head;
	void	*content;

	if (lst == NULL)
		return (0);
	p = lst;
	head = NULL;
	while (p)
	{
		content = f(p->content);
		elem = ft_lstnew(content);
		if (elem == NULL)
		{
			ft_lstclear(&head, del);
			if (content != NULL)
				del(content);
			return (0);
		}
		elem->next = NULL;
		ft_lstadd_back(&head, elem);
		p = p->next;
	}
	return (head);
}
