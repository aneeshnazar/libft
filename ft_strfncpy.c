/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 18:31:40 by anazar            #+#    #+#             */
/*   Updated: 2017/11/30 21:07:16 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strfncpy(char *dest, char *src, int width)
{
	int	i;
	int	slen;

	i = 0;
	slen = ft_strlen(src);
	while (i < slen && i < width)
	{
		dest[i] = src[i];
		++i;
	}
}
