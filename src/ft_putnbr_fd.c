/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 16:28:49 by anazar            #+#    #+#             */
/*   Updated: 2017/06/26 21:41:17 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_help_fd(int n, int fd)
{
	if (n >= 10 || n <= -10)
	{
		ft_help_fd(n / 10, fd);
		ft_help_fd(n % 10, fd);
	}
	else
	{
		if (n > 0)
			ft_putchar_fd(n + '0', fd);
		else
			ft_putchar_fd(-n + '0', fd);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_help_fd(n, fd);
}
