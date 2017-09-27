/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 12:33:15 by anazar            #+#    #+#             */
/*   Updated: 2017/06/22 18:47:30 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = 0;
	if (size < dest_len + 1)
		return (src_len + size);
	if (size > dest_len + 1)
	{
		while (i + dest_len < size - 1)
		{
			dest[i + dest_len] = src[i];
			++i;
		}
		dest[i + dest_len] = 0;
	}
	return (dest_len + src_len);
}
