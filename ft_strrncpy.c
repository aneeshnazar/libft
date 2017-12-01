/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 16:58:25 by anazar            #+#    #+#             */
/*   Updated: 2017/11/30 21:07:30 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strrncpy(char *dest, char *src, int width)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	j = (int)(len - width) < 0 ? 0 : len - width;
	while (i < width && j < len)
	{
		dest[j] = src[i];
		++i;
		++j;
	}
}
