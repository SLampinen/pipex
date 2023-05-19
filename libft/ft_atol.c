/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:49:49 by slampine          #+#    #+#             */
/*   Updated: 2023/03/16 09:49:51 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int		sign;
	long	res;
	int		index;

	res = 0;
	sign = 1;
	index = 0;
	while (str[index] == 32 || (str[index] <= 13 && str[index] >= 9))
		index++;
	if (str[index] == '-')
		sign = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		res = res * 10 + (str[index] - '0');
		index++;
	}
	return (res * sign);
}
