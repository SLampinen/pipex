/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:04:51 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 11:52:21 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	rv;
	int		srclen;

	d = dst;
	s = (char *)src;
	srclen = ft_strlen((char *)src);
	while (dstsize > 1 && srclen > 0)
	{
		*d = *s;
		d++;
		s++;
		dstsize--;
		srclen--;
	}
	if (dstsize != 0)
		*d = '\0';
	rv = ft_strlen((char *)src);
	return (rv);
}
