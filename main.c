/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:29:37 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 14:46:31 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	my_check(int *pile, int ref, size_t size, size_t real_size)
{
	size_t	i;

	i = real_size;
	while (--i > size)
	{
		if (pile[i] == ref)
			return (0);
	}
	return (1);
}

static	int	my_atoi(char *s, long *nb, int sig)
{
	if (!*s)
		return (1);
	if (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\v' || *s == '\r'
			|| *s == '\f')
		return (my_atoi(s + 1, nb, sig));
	if (!sig && (*s == '-' || *s == '+'))
		return (my_atoi(s + 1, nb, (*s == '-') ? -1 : 1));
	if (*s < '0' || *s > '9')
		return (0);
	sig = (!sig) ? 1 : sig;
	*nb = 10 * *nb + sig * (*s - '0');
	return (my_atoi(s + 1, nb, sig));
}

static int	my_parse(int ac, char **av, int **pile1, int **pile2)
{
	int		i;
	int		ret;
	long	nb;
	size_t	size;

	i = 0;
	if ((ret = (!my_strcmp(av[1], "-v") ? 1 : 0)))
		i++;
	size = ac - 1 - ret;
	if (!(*pile1 = (int *)malloc((size) * sizeof(int)))
			|| !(*pile2 = (int *)malloc((size) * sizeof(int))))
		return (0);
	while (++i < ac)
	{
		nb = 0;
		if (!my_atoi(av[i], &nb, 0))
			return (0);
		if (nb < INT_MIN || nb > INT_MAX)
			return (0);
		if (!my_check(*pile1, nb, size - i + ret, size))
			return (0);
		(*pile1)[size - i + ret] = (int)nb;
	}
	return ((ret) ? 2 : 1);
}

int			main(int ac, char **av)
{
	int	ret;
	int	*pile1;
	int	*pile2;

	ret = 0;
	pile1 = NULL;
	pile2 = NULL;
	if (ac < 2 || !(ret = my_parse(ac, av, &pile1, &pile2)))
		write(2, "Error", 5);
	else
		my_compute(pile1, pile2, ac - ret, ret);
	write(1, "\n", 1);
	return (my_quit(&pile1, &pile2));
}
