/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:14:16 by tamigore          #+#    #+#             */
/*   Updated: 2018/11/27 19:52:48 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*ft_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

static	int		ft_strccpy(char **content, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	if (!(*content = ft_strnew(i)))
		return (0);
	ft_strncat(*content, str, i);
	return (i);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*file;
	t_list			*list;
	int				r;
	int				i;
	char 			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	list = ft_file(&file, fd);
	if (!(*line = ft_strnew(1)))
		return (-1);
	while ((r = read(fd, buf, BUFF_SIZE)))
	{
		buf[r] = '\0';
		ft_putnbr(r);
		ft_putstr(" : r\n");
		if (!(list->content = ft_strjoin(list->content, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(list->content))
		return (0);
	ft_putstr(list->content);
	ft_putstr(" : list content\n");
	i = ft_strccpy(line, list->content);
	if (i < (int)ft_strlen(list->content))
		list->content += (i + 1);
	else
		ft_strclr(list->content);
	return (1);
}
