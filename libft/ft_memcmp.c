/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 12:34:46 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 13:37:58 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			max;
	unsigned char	*s;
	unsigned char	*d;

	max = 0;
	s = (unsigned char *) str1;
	d = (unsigned char *) str2;
	if (n == 0)
		return (0);
	while (*s == *d && max < (n - 1))
	{
		s++;
		d++;
		max++;
	}
	return (*s - *d);
}
