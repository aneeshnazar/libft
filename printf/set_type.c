/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:50:28 by anazar            #+#    #+#             */
/*   Updated: 2018/04/19 00:31:58 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		set_uint(t_able *table, va_list a_list)
{
	if (ft_is_in(table->format.type, "UO") || table->format.length == L_LONG)
		table->data.lu = va_arg(a_list, unsigned long int);
	else if (!table->format.length ||
			table->format.length == L_SCHAR ||
			table->format.length == L_SHORT)
		table->data.u = va_arg(a_list, unsigned int);
	else if (table->format.length == L_LLONG)
		table->data.llu = va_arg(a_list, unsigned long long int);
	else if (table->format.length == L_INTMAX)
		table->data.ju = va_arg(a_list, uintmax_t);
	else if (table->format.length == L_SIZET)
		table->data.z = va_arg(a_list, size_t);
}

void		set_int(t_able *table, va_list a_list)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D')
		table->data.ld = va_arg(a_list, long);
	else if (!table->format.length ||
			table->format.length == L_SCHAR ||
			table->format.length == L_SHORT)
		table->data.d = va_arg(a_list, int);
	else if (table->format.length == L_LLONG)
		table->data.lld = va_arg(a_list, long long);
	else if (table->format.length == L_INTMAX)
		table->data.jd = va_arg(a_list, intmax_t);
}

void		set_str(t_able *table, va_list a_list)
{
	if (table->format.type == 's' && !table->format.length)
		table->data.s = va_arg(a_list, char *);
	else
		table->data.ls = va_arg(a_list, wchar_t *);
}

void		set_addr(t_able *table, va_list a_list)
{
	table->data.p = va_arg(a_list, void *);
}

void		set_char(t_able *table, va_list a_list)
{
	if (table->format.type == '%')
		table->data.c = '%';
	else if (table->format.type == 'c' && !table->format.length)
		table->data.c = (char)va_arg(a_list, int);
	else
		table->data.lc = (wchar_t)va_arg(a_list, long);
}
