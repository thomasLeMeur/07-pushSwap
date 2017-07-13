/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:58:10 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/14 14:56:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ff(char *debug, char *text, char **buf, int *len)
{
	char	*tmp;
	size_t	size;

	if (len[4] == 2)
	{
		write(1, "\033[31m", 5);
		write(1, debug, my_strlen(debug));
		write(1, "\033[0m\n\n", 6);
	}
	size = my_strlen(text);
	if (!(tmp = ft_memrealloc(*buf, *len, *len + size)))
	{
		if (*buf)
			free(*buf);
		write(2, "Error", 5);
		return (0);
	}
	*buf = tmp;
	ft_memcpy(*buf + *len, text, size);
	*len += size;
	return (1);
}

size_t	my_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	my_end(int opt, int hits, char *buf, int size)
{
	if (opt == 2)
	{
		write(1, "\033[31mNumber of hits : ", 22);
		my_putnbr(hits);
		write(1, "\033[0m\n", 5);
	}
	if (buf)
	{
		if (opt == 2)
			write(1, "\n", 1);
		write(1, "\033[1m\033[4m", 8);
		write(1, buf, size);
		write(1, "\033[0m", 4);
		free(buf);
	}
}

void	my_init1(int *c, int *s, int size, char **buf)
{
	*c = 0;
	*s = 0;
	s[2] = 0;
	*buf = NULL;
	s[1] = size;
}

int		my_init2(int *pile1, int *pile2, int *s, int r[3][5])
{
	r[1][0] = my_swap(pile1, s[1], 1);
	r[1][1] = my_rotate(pile1, s[1], 1);
	r[1][2] = my_reverse(pile1, s[1], 1);
	r[2][0] = my_swap(pile2, s[2], -1);
	r[2][1] = my_rotate(pile2, s[2], -1);
	r[2][2] = my_reverse(pile2, s[2], -1);
	return (1);
}
