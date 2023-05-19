/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:02:46 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 12:02:56 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	abs_num;
	int				sign;

	sign = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sign = -1;
	}
	abs_num = sign * n;
	if (abs_num >= 10)
	{
		ft_putnbr_fd(abs_num / 10, fd);
		ft_putnbr_fd(abs_num % 10, fd);
	}
	else
		ft_putchar_fd(abs_num + '0', fd);
}
