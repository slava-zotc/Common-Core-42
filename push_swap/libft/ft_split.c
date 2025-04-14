/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:22:55 by vzots             #+#    #+#             */
/*   Updated: 2025/04/08 15:58:38 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_get_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_split(size_t i, char **res)
{
	while (i > 0)
	{
		i--;
		free(res[i]);
	}
	free(res);
}

static char	**ft_write_split(char **res, const char *s, size_t n_words, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	while (i < n_words)
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = ft_get_word_len(&s[j], c);
		res[i] = ft_substr(s, j, word_len);
		if (!res[i])
		{
			ft_free_split(i, res);
			return (NULL);
		}
		j += word_len;
		i++;
	}
	res[i] = (NULL);
	return (res);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**res;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res = ft_write_split(res, s, words, c);
	if (!res)
		return (NULL);
	return (res);
}
