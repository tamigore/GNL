/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:20:31 by tamigore          #+#    #+#             */
/*   Updated: 2019/11/19 11:50:41 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	i = ft_strlen(src);
	if (!(copy = (char *)malloc(i + 1)))
		return (0);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strncat(char *s1, char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] && j < n)
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	while (i <= (int)size)
		str[i++] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int		j;
	int		i;
	char	*p;

	j = 0;
	i = ft_strlen(s);
	while (j <= i)
	{
		if (s[j] == c)
		{
			p = &s[j];
			return (p);
		}
		j++;
	}
	return (NULL);
}
