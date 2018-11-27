/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:14:16 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/26 13:56:19 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strccpy(char **cpy, char *str, int nb, int i)
{
	int n;
	int j;

	j = 0;
	n = nb;
	while (str[nb])
	{
		if (str[nb] == '\n')
			break ;
		nb++;
	}
	if (!(cpy[i] = ft_strnew(nb - n)))
		return (0);
	while (str[n] && n < nb)
		cpy[i][j++] = str[n++];
	cpy[i][j] = '\0';
	return (nb);
}

int		get_next_line(const int fd, char **line)
{
	char			*p;
	int				r;
	static int		i;
	static int		nb;
	char 			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(p = ft_strnew(1)))
		return (-1);
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		ft_putnbr(r);
		ft_putstr(" : r\n");
		p = ft_strjoin(p, buf);
	}
	if (r < BUFF_SIZE && !ft_strlen(p))
		return (0);
	ft_putstr(p);
	ft_putstr(" : p\n");
	if (!(nb = ft_strccpy(line, p, nb, i)))
		return (-1);
	line[++i] = NULL;
	return (1);
}
