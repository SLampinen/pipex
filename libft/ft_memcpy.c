/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:43:29 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 13:37:33 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char			*d;
	unsigned char	*s;

	if ((!dest && !source) && n > 0)
		return (NULL);
	d = dest;
	s = (unsigned char *) source;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}
