/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/16 19:09:11 by anazar            #+#    #+#             */
/*   Updated: 2017/07/19 15:56:55 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_num_words(const char *s, int (*f)(char))
{
	size_t		num;

	num = 0;
	while (*s && f)
	{
		while (f(*s))
			++s;
		if (!f(*s) && *s)
		{
			++num;
			while (!f(*s) && *s)
				++s;
		}
	}
	return (num);
}

static size_t	get_word_len(const char *s, size_t start, int (*f)(char))
{
	size_t		i;

	i = 0;
	while (!f(s[start + i]) && s[start + i])
		++i;
	return (i);
}

char			**ft_split_by_function(char const *s, int (*f)(char))
{
	char		**words;
	size_t		num_words;
	size_t		i;
	size_t		start;
	size_t		l;

	i = 0;
	start = 0;
	if (!s || !f)
		return (NULL);
	num_words = get_num_words(s, f);
	if (!(words = (char **)ft_memalloc(sizeof(char *) * (num_words + 1))))
		return (NULL);
	while (i < num_words)
	{
		l = get_word_len(s, start, f);
		if (l > 0)
			words[i++] = ft_strsub(s, start, l);
		start += (l + 1);
	}
	return (words);
}
