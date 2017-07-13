/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:52:14 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 16:11:26 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

void		my_putnbr(int n)
{
	long	nb;
	long	div;
	char	c;

	if (!n)
		return ((void)write(1, "0", 1));
	div = 1;
	nb = (n < 0) ? -(long)n : n;
	if (n < 0)
		write(1, "-", 1);
	div = 1;
	while (div * 10 <= nb)
		div *= 10;
	while (div)
	{
		c = '0' + nb / div;
		write(1, &c, 1);
		nb %= div;
		div /= 10;
	}
}

void		my_debug(int *pile1, int *pile2, int size1, int size2)
{
	int	i;

	i = 0;
	write(1, "\033[32ma: ", 8);
	while (i < size1)
	{
		my_putnbr(pile1[i++]);
		write(1, " ", 1);
	}
	write(1, "\033[0m\n", 5);
	i = 0;
	write(1, "\033[33mb: ", 8);
	while (i < size2)
	{
		my_putnbr(pile2[i++]);
		write(1, " ", 1);
	}
	write(1, "\033[0m\n", 5);
}

int			my_sort(int *pile, int size, int real_size, int sens)
{
	int	i;
	int	prev;

	i = 0;
	prev = pile[i];
	while (++i < size)
	{
		if (sens == -1)
		{
			if (prev < pile[i])
				return (i);
		}
		else
		{
			if (prev > pile[i])
				return (i);
		}
		prev = pile[i];
	}
	return ((size == real_size) ? 0 : i);
}

int			my_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (s1 - s2);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((s1[i] - s2[i]));
}

int			my_quit(int **pile1, int **pile2)
{
	if (*pile1)
		free(*pile1);
	if (*pile2)
		free(*pile2);
	return (0);
}
