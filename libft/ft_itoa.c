/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:31:12 by slampine          #+#    #+#             */
/*   Updated: 2022/11/11 10:33:00 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_digits(int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				digits;
	unsigned int	abs_num;

	digits = get_digits(n);
	if (digits == 0)
		digits++;
	abs_num = n;
	if (n < 0)
	{
		abs_num = -1 * n;
		digits++;
	}
	str = malloc(digits + 1);
	if (!str)
		return (NULL);
	str[digits] = '\0';
	while (digits--)
	{
		str[digits] = abs_num % 10 + '0';
		abs_num = abs_num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
