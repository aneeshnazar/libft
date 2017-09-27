/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 17:11:08 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 11:49:36 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	i = ft_strlen(to_find);
	while (ft_strncmp(str, to_find, i) != 0)
	{
		if (!*str)
			return (NULL);
		++str;
	}
	return ((char *)(str));
}
