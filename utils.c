/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:10:03 by slampine          #+#    #+#             */
/*   Updated: 2023/06/20 12:10:04 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	dup_n_close(int *tab, int file, int num)
{
	int	i;

	i = 0;
	dup2(file, num);
	if (num == 1)
		dup2(tab[0], 0);
	if (num == 0)
		dup2(tab[1], 1);
	while (tab[i])
	{
		close(tab[i]);
		i++;
	}
	close(file);
}
