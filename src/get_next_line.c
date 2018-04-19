/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anazar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 01:08:51 by anazar            #+#    #+#             */
/*   Updated: 2017/09/27 13:53:59 by anazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FD_ fd % 256

void	resize(int fd, t_gnl *str)
{
	char	tmp[BUFF_SIZE + 1];
	char	*to_del;

	ft_bzero(tmp, BUFF_SIZE + 1);
	str->bytes_read = read(fd, tmp, BUFF_SIZE);
	to_del = str->str;
	str->str = ft_strjoin(str->str, tmp);
	free(to_del);
}

int		check_newline(t_gnl *str, char **line)
{
	char		*tmp;

	if ((tmp = ft_strchr(str->str, '\n')))
	{
		*tmp = 0;
		*line = ft_strdup(str->str);
		ft_memmove(str->str, tmp + 1, ft_strlen(tmp + 1) + 1);
		str->last = 0;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	str[256];

	if (!line || fd < 0)
		return (-1);
	str[FD_].bytes_read = 1;
	if (!str[FD_].str && !(str[FD_].str = ft_strnew(1)))
		return (-1);
	while (str[FD_].bytes_read > 0)
	{
		if (check_newline(&str[FD_], line))
			return (1);
		resize(fd, &str[FD_]);
	}
	if (!str[FD_].bytes_read && !str[FD_].last &&
		ft_strlen(str[FD_].str))
	{
		*line = ft_strdup(str[FD_].str);
		str[FD_].last = 1;
		return (1);
	}
	return (str[FD_].bytes_read);
}
