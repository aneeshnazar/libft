/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:20:55 by anazar            #+#    #+#             */
/*   Updated: 2018/04/19 00:32:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		is_good(t_able *table)
{
	if ((TYPE == 'S' || (TYPE == 's' && LENGTH == L_LONG)) ||
		(TYPE == 'C' || (TYPE == 'c' && LENGTH == L_LONG)))
		return (0);
	else
		return (ft_is_in(TYPE, "spdDioOuUxXc%")) ? 1 : 0;
}

int		is_neg(t_able *table)
{
	if (LENGTH == L_LONG || LENGTH == L_SIZET || TYPE == 'D')
		return (table->data.ld < 0);
	else if (!LENGTH)
		return (table->data.d < 0);
	else if (LENGTH == L_SHORT)
		return (table->data.hhd < 0);
	else if (LENGTH == L_SCHAR)
		return (table->data.hd < 0);
	else if (LENGTH == L_LLONG)
		return (table->data.lld < 0);
	else if (LENGTH == L_INTMAX)
		return (table->data.jd < 0);
	return (0);
}

int		is_sign(t_able *table)
{
	if (ft_is_in(table->format.type, "dDi"))
	{
		if (is_neg(table))
			return (1);
		else if (check_plus(table))
			return (1);
	}
	return (0);
}

char	*zero_str(int num)
{
	char	*str;

	if (!(str = (char *)malloc(num + 1)))
		return (NULL);
	ft_memset(str, '0', num);
	str[num] = 0;
	return (str);
}
