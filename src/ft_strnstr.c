/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 14:49:46 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 11:51:01 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	it;

	i = 0;
	it = 0;
	if (!*to_find)
		return ((char *)str);
	i = ft_strlen(to_find);
	while (ft_strncmp(&str[it], to_find, i) != 0)
	{
		if (!str[it] || it >= (len - i))
			return (NULL);
		++it;
	}
	if (i > len)
		return (NULL);
	return ((char *)(&str[it]));
}
