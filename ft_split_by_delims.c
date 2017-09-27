/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_delims.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 15:50:55 by anazar            #+#    #+#             */
/*   Updated: 2017/07/13 01:29:46 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_delim(char c, char *delims)
{
	while (*delims && c)
	{
		if (c == *delims)
			return (1);
		++delims;
	}
	return (0);
}

static size_t	get_num_words(const char *s, char *delims)
{
	size_t		num;

	num = 0;
	while (*s)
	{
		while (is_delim(*s, delims))
			++s;
		if (!is_delim(*s, delims) && *s)
		{
			++num;
			while (!is_delim(*s, delims) && *s)
				++s;
		}
	}
	return (num);
}

static size_t	get_word_len(const char *s, size_t start, char *delims)
{
	size_t		i;

	i = 0;
	while (!is_delim(s[start + i], delims) && s[start + i])
		++i;
	return (i);
}

char			**ft_split_by_delims(const char *s, char *c)
{
	char		**words;
	size_t		num_words;
	size_t		i;
	size_t		start;
	size_t		l;

	i = 0;
	start = 0;
	if (!s || !c)
		return (NULL);
	num_words = get_num_words(s, c);
	if (!(words = (char **)ft_memalloc(sizeof(char *) * (num_words + 1))))
		return (NULL);
	while (i < num_words)
	{
		l = get_word_len(s, start, c);
		if (l > 0)
			words[i++] = ft_strsub(s, start, l);
		start += (l + 1);
	}
	return (words);
}
