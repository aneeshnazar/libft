/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:18:59 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 21:41:33 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_help(int n)
{
	if (n >= 10 || n <= -10)
	{
		ft_help(n / 10);
		ft_help(n % 10);
	}
	else
	{
		if (n > 0)
			ft_putchar(n + '0');
		else
			ft_putchar(-n + '0');
	}
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	ft_help(n);
}
