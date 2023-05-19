/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srclenampine <marvin@42.fr>                    +#+  +:+       +#+    */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:15:50 by srclenampine          #+#    #+#         */
/*   Updated: 2022/11/11 12:05:37 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	srclen;

	i = 0;
	if (!s)
		return (NULL);
	srclen = ft_strlen((char *)s);
	if (srclen < start)
	{
		new = ft_calloc(1, sizeof(char *));
		return (new);
	}
	new = malloc((ft_min(len, srclen - start) + 1));
	if (!new)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		new[i] = s[start];
		start++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
