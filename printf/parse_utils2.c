/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:35:16 by anazar            #+#    #+#             */
/*   Updated: 2018/04/19 00:30:44 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void		length_val(t_format *t, char *format, int *start)
{
	if (format[*start] == 'h')
		t->length = (format[*start + 1] == 'h') ? L_SCHAR : L_SHORT;
	else if (format[*start] == 'l')
		t->length = (format[*start + 1] == 'l') ? L_LLONG : L_LONG;
	else
		t->length = (format[*start] == 'j') ? L_INTMAX : L_SIZET;
}

int				parse_length(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC%"))
		return (0);
	else if (ft_is_in(format[*start], "hljz"))
	{
		length_val(t, format, start);
		*start += (t->length == L_SCHAR || t->length == L_LLONG) ? 2 : 1;
		return (1);
	}
	else
	{
		t->is_good = 0;
		return (-1);
	}
}

int				parse_type(t_format *t, char *format, int *start)
{
	if (ft_is_in(format[*start], "sSpdDioOuUxXcC") ||
		(format[*start] == '%' && *start >= 1))
	{
		t->type = format[*start];
		++*start;
		return (1);
	}
	else
	{
		t->is_good = 0;
		return (-1);
	}
}

void			parse_precision(t_format *t, char *format, int *start)
{
	int			tmp;

	tmp = *start;
	if (format[tmp] == '.')
	{
		++tmp;
		while (ft_isdigit(format[tmp]))
			++tmp;
		t->precision = ft_atoi(&format[*start + 1]);
		*start = tmp;
	}
}

void			parse_width(t_format *t, char *format, int *start)
{
	int			tmp;

	tmp = *start;
	if (ft_isdigit(format[tmp]))
	{
		while (ft_isdigit(format[tmp]))
			++tmp;
		t->width = ft_atoi(&format[*start]);
		*start = tmp;
	}
}
