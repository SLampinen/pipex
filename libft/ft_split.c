/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slampine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:32:39 by slampine          #+#    #+#             */
/*   Updated: 2022/11/11 12:28:14 by slampine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_array(char **array, int i)
{
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
	free (array);
}

static char	*dupl_word(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

static int	count_words(char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	**do_split(char **array, char *str, char c)
{
	int		wordnum;
	int		start;
	size_t	end;

	start = -1;
	end = 0;
	wordnum = 0;
	while (end <= ft_strlen(str))
	{
		if (str[end] != c && start == -1)
			start = end;
		else if ((str[end] == c || end == ft_strlen(str)) && start >= 0)
		{
			array[wordnum++] = dupl_word(str, start, end);
			if (!array[wordnum - 1])
			{
				free_array(array, wordnum);
				return (NULL);
			}
			start = -1;
		}
		end++;
	}
	array[wordnum] = 0;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = malloc((count_words((char *)s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	array = do_split(array, (char *)s, c);
	if (!array)
		return (0);
	return (array);
}
