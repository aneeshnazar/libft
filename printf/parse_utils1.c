/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:34:38 by anazar            #+#    #+#             */
/*   Updated: 2018/04/19 00:31:18 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void			parse_flags(t_format *t, char *format, int *start)
{
	while (ft_is_in(format[*start], "0-+ #"))
	{
		if (format[*start] == '0')
			t->f_zero += 1;
		if (format[*start] == '-')
			t->f_minus += 1;
		if (format[*start] == '+')
			t->f_plus += 1;
		if (format[*start] == ' ')
			t->f_space += 1;
		if (format[*start] == '#')
			t->f_hash += 1;
		++*start;
	}
}

t_format		init_format(void)
{
	t_format	n;

	n.f_minus = 0;
	n.f_plus = 0;
	n.f_space = 0;
	n.f_zero = 0;
	n.f_hash = 0;
	n.width = -1;
	n.precision = -1;
	n.length = 0;
	n.type = 0;
	n.str = NULL;
	return (n);
}

t_format		parse_format(char *str)
{
	t_format	new_f;
	int			pos;

	new_f = init_format();
	pos = 1;
	new_f.str = ft_strdup(str);
	new_f.is_good = 0;
	parse_flags(&new_f, str, &pos);
	parse_width(&new_f, str, &pos);
	parse_precision(&new_f, str, &pos);
	if (parse_length(&new_f, str, &pos) == -1)
		return (new_f);
	if (parse_type(&new_f, str, &pos) == -1)
		return (new_f);
	new_f.is_good = 1;
	return (new_f);
}
