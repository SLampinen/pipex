/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:21:25 by slampine          #+#    #+#             */
/*   Updated: 2022/11/09 11:58:26 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	char	*temp;
	int		i;

	i = 0;
	if (!s || !f)
		return ;
	temp = (char *)s;
	while (*temp != '\0')
	{
		f(i, temp);
		i++;
		temp++;
	}
}
