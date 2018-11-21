/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:35 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/21 19:26:48 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		err;
	char	**tab;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("open fail.\n");
			return (0);
		}
		if (!(tab = (char **)malloc(sizeof(char *) * 2)))
			return (-1);
		while ((err = get_next_line(fd, tab)) == 1)
		{
			if (err == -1)
			{
				ft_putstr("get next line fail.\n");
				return (0);
			}
		}
		close(fd);
	}
	return (0);
}
