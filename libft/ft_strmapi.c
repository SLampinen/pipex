/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:15:06 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 11:49:24 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*temp;
	int		count;
	char	*res;

	count = 0;
	if (!s)
		return (0);
	temp = (char *)s;
	while (*temp != '\0')
	{
		count++;
		temp++;
	}
	res = malloc(count + 1);
	if (!res)
		return (0);
	count = 0;
	while (s[count] != '\0')
	{
		res[count] = f(count, s[count]);
		count++;
	}
	res[count] = '\0';
	return (res);
}
