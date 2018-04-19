/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 19:09:27 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:08:02 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	set_tmp_char(t_able *table)
{
	if (ft_is_in(table->format.type, "c%") && !table->format.length)
		table->tmp = ft_ctos(table->data.c);
	else
		table->wtmp = ft_wctos(table->data.lc);
}

void	set_tmp_str(t_able *table)
{
	if (table->format.type == 's' && !table->format.length)
		table->tmp = (!table->data.s) ? ft_strdup("(null)") :
			ft_strdup(table->data.s);
	else
		table->wtmp = table->data.ls;
}

void	set_tmp_int(t_able *table)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D' ||
		table->format.length == L_LLONG ||
		table->format.length == L_INTMAX)
		table->tmp = ft_jtoa(table->data.ld);
	else if (!table->format.length)
		table->tmp = ft_jtoa(table->data.d % MOD_U);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_jtoa(table->data.hd % MOD_SH);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_jtoa(table->data.hhd % MOD_SC);
}

void	set_tmp_uns(t_able *table)
{
	if (ft_is_in(table->format.type, "UO") ||
		table->format.length == L_LONG ||
		table->format.length == L_LLONG ||
		table->format.length == L_INTMAX ||
		table->format.length == L_SIZET)
		table->tmp = ft_jutoa(table->data.lu, table->format.type);
	else if (table->format.type == 'p')
	{
		table->tmp = ft_jutoa(table->data.lu, 'x');
		table->format.f_hash = 1;
	}
	else if (!table->format.length)
		table->tmp = ft_jutoa(table->data.u % MOD_U, table->format.type);
	else if (table->format.length == L_SHORT)
		table->tmp = ft_jutoa(table->data.hu % MOD_SH, table->format.type);
	else if (table->format.length == L_SCHAR)
		table->tmp = ft_jutoa(table->data.hhu % MOD_SC, table->format.type);
}

void	set_tmp(t_able *table)
{
	if (ft_is_in(table->format.type, "sS"))
		set_tmp_str(table);
	else if (ft_is_in(table->format.type, "dDi"))
		set_tmp_int(table);
	else if (ft_is_in(table->format.type, "puUoOxX"))
		set_tmp_uns(table);
	else if (ft_is_in(table->format.type, "cC%"))
		set_tmp_char(table);
	else
		set_tmp_char(table);
}
