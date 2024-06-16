/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfelida <mfelida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:39 by mfelida           #+#    #+#             */
/*   Updated: 2023/10/26 11:47:13 by mfelida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*head;
	t_list	*curr;

	if (!lst)
		return (NULL);
	head = ft_lstnew(NULL);
	if (!head)
		return (NULL);
	head->content = f(lst->content);
	lst = lst->next;
	curr = head;
	while (lst)
	{
		curr->next = ft_lstnew(NULL);
		if (!(curr->next))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		curr = curr->next;
		curr->content = f(lst->content);
		lst = lst->next;
	}
	return (head);
}
