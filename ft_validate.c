/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <anazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:51:28 by anazar            #+#    #+#             */
/*   Updated: 2017/12/26 17:26:03 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	valid_number(char *str, char c, int *amt)
{
	char	*orig;

	orig = str;
	if (!ft_isdigit(*str) && *str != '-')
		return (0);
	while (*str != c)
	{
		if (!*str)
			return (0);
		++str;
	}
	*amt = str - orig;
	return (1);
}

static int	valid_str(char *str, char *format, int *amt)
{
	char	*orig;

	orig = str;
	if (ft_iswhitespace(*str))
		return (0);
	while (*str != *format)
	{
		if (!*str || ft_iswhitespace(*str))
			return (0);
		++str;
	}
	*amt = str - orig;
	return (1);
}

static int	validate_format(char *format, char *str, int *amt)
{
	++format;
	if (*format == 'd')
		if (!valid_number(str, *(format + 1), amt))
			return (0);
	if (*format == 's')
		if (!valid_str(str, format + 1, amt))
			return (0);
	return (1);
}

int			ft_general_validate(char *format, char *str)
{
	int		amt;

	if (!format || !str)
		return (0);
	while (*format && *str)
	{
		if (*format == '%')
		{
			if (!validate_format(format, str, &amt))
				return (0);
			format += 2;
			str += amt;
		}
		else
		{
			if (*format != *str)
				return (0);
			++format;
			++str;
		}
	}
	return (1);
}
