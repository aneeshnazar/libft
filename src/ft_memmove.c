/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 10:49:05 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 15:05:24 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*csrc;
	unsigned char	*cdst;
	size_t			i;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (csrc < cdst)
	{
		while ((int)(--len) >= 0)
			cdst[len] = csrc[len];
	}
	else
	{
		while (i < len)
		{
			cdst[i] = csrc[i];
			++i;
		}
	}
	return (dst);
}
