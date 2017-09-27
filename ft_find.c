/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 19:21:16 by anazar            #+#    #+#             */
/*   Updated: 2017/07/08 16:20:29 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_find(char *str, char *to_find)
{
	size_t	i;
	size_t	tf_len;
	size_t	st_len;

	i = 0;
	st_len = ft_strlen(str);
	tf_len = ft_strlen(to_find);
	while (i < st_len)
	{
		if (ft_strncmp(str, to_find, tf_len) == 0)
			return ((int)i);
		++i;
		++str;
	}
	return (-1);
}
