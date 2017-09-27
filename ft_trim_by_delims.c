/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_by_delims.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:15:35 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 14:40:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_delims(char c, char *delims)
{
	while (*delims)
	{
		if (c == *delims)
			return (1);
		++delims;
	}
	return (0);
}

char		*ft_trim_by_delims(const char *s, char *delims)
{
	size_t	f;
	size_t	l;
	char	*str;

	if (!s)
		return (NULL);
	f = 0;
	l = ft_strlen(s) - 1;
	while (in_delims(s[f], delims) && s[f])
		++f;
	while (in_delims(s[l], delims) && f < l)
		--l;
	if (!(str = ft_strsub(s, f, (l - f) + 1)))
		return (NULL);
	return (str);
}
