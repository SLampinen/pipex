/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:21:18 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 14:54:13 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int		stop;
	char	d;
	int		end;
	char	*s;

	d = (char )c;
	s = (char *)str;
	end = 0;
	stop = 0;
	while (*s != '\0')
	{
		s++;
		end++;
	}
	while (stop == 0)
	{
		if (*s == d)
			return (s);
		if (end == 0)
			stop = 1;
		end--;
		s--;
	}
	return ((char *)0);
}
