/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mroturea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 13:35:23 by mroturea          #+#    #+#             */
/*   Updated: 2016/03/22 13:56:23 by mroturea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int				ret;
	static char		*tmp;
	char			*i;
	char			buf[BUFF_SIZE + 1];

	tmp = ft_strnew(0);
	while (!(i = ft_strchr(tmp, '\n'))
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(tmp, buf);
	}
	*line = ft_strdup(tmp);
	if (fd < 0 || ret < 0 || !line)
		return (-1);
	if (ret == 0)
		return (0);
	return (1);
}
