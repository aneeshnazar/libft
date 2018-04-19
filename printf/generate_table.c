/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 19:40:38 by anazar            #+#    #+#             */
/*   Updated: 2017/08/21 16:32:21 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_able		*generate_table(char *format, va_list a_list, int *num)
{
	t_format	*formats;
	t_able		*out;
	int			i;

	i = 0;
	formats = get_format(format, num);
	out = (t_able *)ft_memalloc(sizeof(t_able) * (*num + 1));
	while (i < *num)
	{
		out[i].format = formats[i];
		set_data(&out[i], a_list);
		if (is_good(&out[i]))
			set_output(&out[i]);
		++i;
	}
	free(formats);
	return (out);
}
