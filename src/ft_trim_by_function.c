/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_by_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:14:29 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 14:40:52 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_trim_by_function(const char *s, int (*f)(char))
{
	size_t	i;
	size_t	l;
	char	*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	l = ft_strlen(s) - 1;
	while (f(s[i]) && s[i])
		++i;
	while (f(s[l]) && i < l)
		--l;
	if (!(str = ft_strsub(s, i, (l - i) + 1)))
		return (NULL);
	return (str);
}
