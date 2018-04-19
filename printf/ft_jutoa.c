/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 17:51:08 by anazar            #+#    #+#             */
/*   Updated: 2017/08/17 14:20:28 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_intlen(uintmax_t n, int base)
{
	int		i;

	i = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n /= base;
		++i;
	}
	return (i);
}

static char	get_digit(uintmax_t n)
{
	if (n <= 9)
		return (n + '0');
	else
		return (n - 10 + 'A');
}

static void	help(char *buffer, int base, uintmax_t num, int index)
{
	if (num >= (unsigned)base)
	{
		help(buffer, base, num / base, index - 1);
		help(buffer, base, num % base, index);
	}
	else
		buffer[index] = get_digit(num);
}

static void	str_tolower(char *buffer)
{
	while (*buffer)
	{
		*buffer = ft_tolower(*buffer);
		++buffer;
	}
}

char		*ft_jutoa(uintmax_t n, char base)
{
	int		len;
	char	*buffer;
	int		b;

	if (ft_is_in(base, "uU"))
		b = 10;
	else if (ft_is_in(base, "oO"))
		b = 8;
	else
		b = 16;
	len = ft_intlen(n, b);
	if (!(buffer = ft_strnew(len)))
		return (NULL);
	--len;
	help(buffer, b, n, len);
	if (base == 'x')
		str_tolower(buffer);
	return (buffer);
}
