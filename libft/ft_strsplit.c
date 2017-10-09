/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhallste <rhallste@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 10:03:06 by rhallste          #+#    #+#             */
/*   Updated: 2017/09/25 15:21:19 by rhallste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static char	*forward(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static int	count_words(char const *s, char c)
{
	int i;

	i = 0;
	while (s && *s)
	{
		s = forward(s, c);
		if (*s)
			i++;
		s = ft_strchr(s, c);
	}
	return (i);
}

static void	*free_all(char ***words, int last_index)
{
	while (last_index >= 0)
	{
		free(*(words[last_index]));
		*words[last_index] = NULL;
		last_index--;
	}
	free(*words);
	*words = NULL;
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*next;
	int		word_count;
	int		i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	if (!(words = (char **)ft_memalloc(sizeof(char *) * (word_count + 1))))
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		s = forward(s, c);
		next = ft_strchr(s, c);
		words[i] = (next) ? ft_strsub(s, 0, next - s) : ft_strdup(s);
		if (!(words[i]))
			return (free_all(&words, i - 1));
		s = next;
		i++;
	}
	words[word_count] = NULL;
	return (words);
}
