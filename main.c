/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:31:23 by tamigore          #+#    #+#             */
/*   Updated: 2018/12/05 14:56:15 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(void)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("42file", O_RDONLY)) == -1)
	{
		ft_putstr("open fail\n");
		return (0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		ft_putstr("passage numero ");
		ft_putnbr(i++);
		ft_putstr(" :\nligne : ");
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	return (0);
}
