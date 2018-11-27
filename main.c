/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:30:35 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/26 13:58:09 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int 	i;
	int		err = 1;
	char	**tab;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_putstr("open fail.\n");
			return (0);
		}
		if (!(tab = (char **)malloc(sizeof(char *) * 8)))
			return (-1);
		while (err == 1)
		{
			err = get_next_line(fd, tab);
			if (err == -1)
			{
				ft_putstr("get next line fail.\n");
				return (0);
			}
			i++;
			ft_putnbr(err);
			ft_putstr(" : err\n");
			ft_puttab(tab);
			ft_putstr(" : tab\n Passage numero ");
			ft_putnbr(i);
			ft_putstr("\n\n");
		}
		close(fd);
	}
	return (0);
}
