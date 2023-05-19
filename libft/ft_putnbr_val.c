/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:59:43 by slampine          #+#    #+#             */
/*   Updated: 2022/12/12 10:35:44 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_digits(int n)
{
	unsigned int	abs_num;
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i = 1;
		abs_num = n * -1;
	}
	else
	abs_num = n;
	while (abs_num)
	{
		abs_num /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_val(int n)
{
	unsigned int	abs_num;
	int				sign;
	int				ret;

	ret = get_digits(n);
	sign = 1;
	if (n < 0)
	{
		ft_putchar_val('-');
		sign = -1;
	}
	abs_num = sign * n;
	if (abs_num >= 10)
	{
		ft_putnbr_val(abs_num / 10);
		ft_putnbr_val(abs_num % 10);
	}
	else
		ft_putchar_val(abs_num + '0');
	return (ret);
}
