/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:56:18 by slampine          #+#    #+#             */
/*   Updated: 2022/12/12 10:35:51 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putptr_val(unsigned long long n, int ft)
{
	int	ret;

	ret = 0;
	if (ft)
		ret += ft_putstr_val("0x");
	if (n >= 16)
	{
		ret += ft_putptr_val(n / 16, 0);
		ret += ft_putptr_val(n % 16, 0);
	}
	else if (n > 9)
		ret += ft_putchar_val(n + 'W');
	else
		ret += ft_putchar_val(n + '0');
	return (ret);
}
