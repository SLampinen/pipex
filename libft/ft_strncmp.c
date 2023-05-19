/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:58:12 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 13:42:42 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	max;

	max = 1;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 != '\0' && *str2 != '\0' && max < n)
	{
		str1++;
		str2++;
		max++;
	}
	if ((unsigned char) *str1 > (unsigned char) *str2)
		return (1);
	if ((unsigned char) *str1 < (unsigned char) *str2)
		return (-1);
	return (0);
}
