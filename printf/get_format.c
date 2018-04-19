/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:44:56 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 15:15:45 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*ft_copy_until(char *str, int start)
{
	char		*out;
	int			i;

	i = 0;
	if (!(out = ft_strnew(100)))
		return (NULL);
	while (str[start])
	{
		out[i] = str[start];
		++start;
		if (ft_is_in(out[i], "sSpdDioOuUxXcC") || (out[i] == '%' && i >= 1))
			break ;
		++i;
	}
	return (out);
}

t_format	*get_format(char *format, int *num)
{
	t_format	*out;
	int			i;
	int			out_it;
	char		*str;

	i = 0;
	out_it = 0;
	*num = ft_countif(format, '%');
	out = (t_format *)ft_memalloc(sizeof(t_format) * (*num + 1));
	while (format[i] && out_it < *num)
	{
		if (format[i] == '%' && format[i])
		{
			str = ft_copy_until(format, i);
			if (str[0] == '%' && str[ft_strlen(str) - 1] == '%')
				--*num;
			out[out_it++] = parse_format(str);
			i += ft_strlen(str);
			ft_strdel(&str);
		}
		else
			++i;
	}
	return (out);
}
