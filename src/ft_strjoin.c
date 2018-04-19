/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:01:33 by anazar            #+#    #+#             */
/*   Updated: 2017/07/15 18:14:41 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(str = ft_strnew(s1_len + s2_len)))
		return (NULL);
	while (i < s1_len)
	{
		str[i] = s1[i];
		++i;
	}
	while (j < s2_len)
	{
		str[i++] = s2[j];
		++j;
	}
	return (str);
}
