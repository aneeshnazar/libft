/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 11:05:00 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 12:30:14 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*csrc;
	size_t				i;

	csrc = (const unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == (unsigned char)c)
			return ((void *)&s[i]);
		++i;
	}
	return (NULL);
}
