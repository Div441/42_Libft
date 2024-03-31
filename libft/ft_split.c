/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbhatia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:15:24 by dbhatia           #+#    #+#             */
/*   Updated: 2023/09/22 15:15:37 by dbhatia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	split;

	i = 0;
	split = 0;
	while (*str)
	{
		if (*str != c && split == 0)
		{
			split = 1;
			i++;
		}
		else if (*str == c)
			split = 0;
		str++;
	}
	return (i);
}

static char	*word_duplicate(const char *str, int start, int end)
{
	char	*word;
	int		i;
	int		l;

	l = end - start;
	i = 0;
	word = malloc((l + 1) * sizeof(char));
	if(!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_duplicate(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
