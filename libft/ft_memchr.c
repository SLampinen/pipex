/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:56:50 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 12:13:38 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	d;
	char	*rv;
	char	*s;

	s = (char *)str;
	rv = (void *)0;
	d = c;
	while (n > 0)
	{
		if (*s == d)
			return (s);
		s++;
		n--;
	}
	return (rv);
}
