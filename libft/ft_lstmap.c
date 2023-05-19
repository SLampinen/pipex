/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:07:49 by slampine          #+#    #+#             */
/*   Updated: 2022/11/15 10:36:45 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*firstnode;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	firstnode = ft_lstnew(f(lst->content));
	if (!firstnode)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!newnode)
		{
			ft_lstclear(&firstnode, del);
			return (NULL);
		}
		ft_lstadd_back(&firstnode, newnode);
		lst = lst->next;
	}
	return (firstnode);
}
