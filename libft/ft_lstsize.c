/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:56:48 by slampine          #+#    #+#             */
/*   Updated: 2022/11/15 10:36:59 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		res;
	t_list	*newnode;

	newnode = lst;
	res = 1;
	if (!lst)
		return (0);
	while (newnode->next != NULL)
	{
		newnode = newnode->next;
		res++;
	}
	return (res);
}
