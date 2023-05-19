/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:25:54 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 11:57:35 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		inds;
	int		indd;

	indd = 0;
	inds = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen((char *) s1) + ft_strlen((char *) s2) + 1);
	if (!str)
		return (NULL);
	while (s1[inds] != '\0')
	{
		str[indd++] = s1[inds++];
	}
	inds = 0;
	while (s2[inds] != '\0')
	{
		str[indd++] = s2[inds++];
	}
	str[indd] = '\0';
	return (str);
}
