/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 10:32:05 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 14:27:10 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void	handle_hash_sign(t_able *table)
{
	int		i;
	char	c;

	i = 0;
	if (table->format.type == 'x')
		i = ft_find(table->output, "x");
	else if (table->format.type == 'X')
		i = ft_find(table->output, "X");
	if (i != -1)
	{
		c = table->output[i];
		table->output[i] = table->output[1];
		table->output[1] = c;
	}
}

static void	handle_sign(t_able *table)
{
	int		i;
	char	c;

	i = 0;
	if (ft_is_in('+', table->output))
		i = ft_find(table->output, "+");
	else if (ft_is_in('-', table->output))
		i = ft_find(table->output, "-");
	else
		i = 0;
	if (i != -1)
	{
		c = table->output[i];
		table->output[i] = table->output[0];
		table->output[0] = c;
	}
}

void		fix_sign(t_able *table)
{
	if (table->format.f_hash)
		handle_hash_sign(table);
	if (ft_is_in(table->format.type, "dDi"))
		handle_sign(table);
}
