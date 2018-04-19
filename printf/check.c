/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:25:58 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:26:53 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		check_hash(t_able *table)
{
	if (table->format.f_hash)
	{
		if (ft_is_in(table->format.type, "oO"))
			return (1);
		else if (table->format.type == 'x')
			return (2);
		else if (table->format.type == 'X')
			return (3);
	}
	return (0);
}

int		check_zero(t_able *table)
{
	if (table->format.f_zero)
		if (ft_is_in(table->format.type, "dDiuUxXoO"))
			if (table->format.width != -1)
				return (1);
	return (0);
}

int		check_space(t_able *table)
{
	if (table->format.f_space && !table->format.f_plus)
		if (ft_is_in(table->format.type, "di"))
			if (table->data.d > 0)
				return (1);
	return (0);
}

int		check_minus(t_able *table)
{
	return (table->format.f_minus);
}

int		check_plus(t_able *table)
{
	if (table->format.f_plus)
		return (!is_neg(table));
	return (0);
}
