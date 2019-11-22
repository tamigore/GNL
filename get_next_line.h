/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:57:04 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/21 17:56:27 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				get_next_line(int fd, char **line);
char			*ft_strdup(char *src);
int				ft_strlen(char *s);
char			*ft_strncat(char *s1, char *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strchr(char *s, int c);

typedef	struct	s_list
{
	void			*content;
	int				fd;
	struct s_list	*next;
}				t_list;

#endif
