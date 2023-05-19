/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:16:17 by slampine          #+#    #+#             */
/*   Updated: 2022/12/12 10:47:48 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_puthex_val(unsigned int n, int caps)
{
	int				ret;
	int				rem;

	rem = 0;
	ret = 0;
	if (n >= 16)
	{
		ret += ft_puthex_val(n / 16, caps);
		ret += ft_puthex_val(n % 16, caps);
	}
	else if (n > 9)
	{
		if (caps)
			ret += ft_putchar_val(n + '7');
		else
			ret += ft_putchar_val(n + 'W');
	}
	else
		ret += ft_putchar_val(n + '0');
	return (ret);
}
