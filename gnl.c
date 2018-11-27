/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:05:24 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/27 19:18:23 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char		*str;
	char			buf[BUFF_SIZE + 1];
	int				i;
	int				r;

	if (!line || !fd)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while (r = read(fd, buf, BUFF_SIZE))
	{
		buf[r] = '\0';
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}

}
