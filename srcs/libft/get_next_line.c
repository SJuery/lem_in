/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjuery <sjuery@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 23:04:48 by sjuery            #+#    #+#             */
/*   Updated: 2018/01/13 12:21:37 by sjuery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	next_line(char **overflow, char **line, int fd, int ret)
{
	char		*tmp;
	int			len;

	len = 0;
	while (overflow[fd][len] && overflow[fd][len] != '\n')
		len++;
	if (overflow[fd][len] == '\n')
	{
		*line = ft_strsub(overflow[fd], 0, len);
		tmp = ft_strdup(overflow[fd] + len + 1);
		free(overflow[fd]);
		overflow[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(overflow[fd]);
		free(overflow[fd]);
		overflow[fd] = 0;
		if (ret == BUFF_SIZE)
			return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*overflow[4864];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line || fd > 4864)
		return (-1);
	if (!overflow[fd])
		overflow[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(overflow[fd], buf);
		free(overflow[fd]);
		overflow[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (!ret && (!overflow[fd] || !overflow[fd][0]))
		return (0);
	return (next_line(overflow, line, fd, ret));
}
