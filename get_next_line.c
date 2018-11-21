/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:14:16 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/21 19:26:46 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strccat(char *cpy, char *str, char c)
{
	int	i;
	int j;

	i = 0;
	j = ft_strlen(cpy);
	while (str[i])
	{
		if (str[i] == c)
			break ;
		cpy[j++] = str[i++];
	}
	cpy[j + 1] = '\0';
	return (cpy);
}

int		get_next_line(const int fd, char **line)
{
	static int		i;
	ssize_t			r;
	char 			*str;

	if (!(str = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	if (!(line[i] = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while (ft_strchr(str, '\n') == NULL)
	{
		if ((r = read(fd, str, BUFF_SIZE)) < 0)
		{
			ft_putstr("read fail.\n");
			return (-1);
		}
		str[r] = '\0';
		ft_strccat(line[i], str, '\n');
	}
	line[++i] = NULL;
	ft_puttab(line);
	if (r != 42)
		return (0);
	return (1);
}
