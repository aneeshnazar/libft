/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:58:36 by anazar            #+#    #+#             */
/*   Updated: 2018/04/18 23:00:09 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	handle_zero(t_able *table)
{
	int	i;

	i = (WIDTH != -1 && PRECISION != -1) ?
	table->format.width - table->format.precision : 0;
	if (ft_is_in(table->format.type, "dDioOuUxX") && table->format.f_zero)
	{
		while (table->output[i])
		{
			if (table->output[i] == ' ')
				table->output[i] = '0';
			else
				break ;
			++i;
		}
		fix_sign(table);
	}
}

void	handle_space(t_able *table)
{
	if (check_space(table) && OUTPUT[0] != ' ')
		OUTPUT = ft_strjoinfree(ft_strdup(" "), OUTPUT);
}

void	handle_hash(t_able *table)
{
	if (table->format.f_hash)
	{
		if (ft_is_in(table->format.type, "oO") && table->data.u != 0)
			table->tmp = ft_strjoinfree(ft_strdup("0"), table->tmp);
		else if ((table->format.type == 'x' && table->data.u != 0)
			|| (table->format.type == 'p'))
			table->tmp = ft_strjoinfree(ft_strdup("0x"), table->tmp);
		else if (table->format.type == 'X' && table->data.u != 0)
			table->tmp = ft_strjoinfree(ft_strdup("0X"), table->tmp);
	}
}
