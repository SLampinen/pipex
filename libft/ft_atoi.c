/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:45:16 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 12:24:23 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
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
