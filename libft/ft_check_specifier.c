/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:54:05 by slampine          #+#    #+#             */
/*   Updated: 2022/12/12 13:15:00 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include "libft.h"

int	ft_check_specifier(va_list	ap, char spec)
{
	int	result;

	result = 0;
	if (spec == 'c')
		result = ft_putchar_val(va_arg(ap, int));
	if (spec == 's')
		result = ft_putstr_val(va_arg(ap, char *));
	if (spec == 'p')
		result = ft_putptr_val(va_arg(ap, unsigned long long), 1);
	if (spec == 'd')
		result = ft_putnbr_val(va_arg(ap, int));
	if (spec == 'i')
		result = ft_putnbr_val(va_arg(ap, int));
	if (spec == 'u')
		result = ft_putunsig_val(va_arg(ap, unsigned int));
	if (spec == 'x')
		result = ft_puthex_val(va_arg(ap, unsigned int), 0);
	if (spec == 'X')
		result = ft_puthex_val(va_arg(ap, unsigned int), 1);
	if (spec == '%')
		result = ft_putchar_val('%');
	return (result);
}
