/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 10:50:04 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 11:55:14 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*s;
	int		srclen;
	size_t	inds;
	size_t	indd;

	inds = 0;
	indd = 0;
	s = (char *) src;
	srclen = ft_strlen((char *)src);
	if (dstsize == 0)
		return (srclen);
	while (dst[indd] && indd < dstsize)
		indd++;
	while (s[inds] && (indd + inds + 1) < dstsize)
	{
		dst[indd + inds] = s[inds];
		inds++;
	}
	if (indd < dstsize)
		dst[indd + inds] = '\0';
	return (srclen + indd);
}
