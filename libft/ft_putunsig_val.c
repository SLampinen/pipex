/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig_val.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:52:53 by slampine          #+#    #+#             */
/*   Updated: 2022/12/12 10:33:36 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putunsig_val(int n)
{
	unsigned int	abs_num;
	int				ret;

	abs_num = n;
	ret = 0;
	if (n < 0)
		abs_num = UINT_MAX + n + 1;
	if (abs_num >= 10)
	{
		ret += ft_putnbr_val(abs_num / 10);
		ret += ft_putnbr_val(abs_num % 10);
	}
	else
		ret += ft_putchar_val(abs_num + '0');
	return (ret);
}
