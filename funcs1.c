/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:00:40 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 13:25:04 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

int	my_sx(int *pile, int size)
{
	int	tmp;

	tmp = pile[size - 2];
	pile[size - 2] = pile[size - 1];
	pile[size - 1] = tmp;
	return (1);
}

int	my_ss(int *pile1, int *pile2, int size1, int size2)
{
	return (my_sx(pile1, size1) && my_sx(pile2, size2));
}

int	my_px(int *pile1, int *pile2, int size1, int size2)
{
	pile1[size1] = pile2[size2 - 1];
	return (1);
}

int	my_rx(int *pile, int size)
{
	int	i;
	int	tmp;

	i = size;
	tmp = pile[i - 1];
	while (--i > 0)
	{
		pile[i] = pile[i - 1];
	}
	pile[i] = tmp;
	return (1);
}

int	my_rr(int *pile1, int *pile2, int size1, int size2)
{
	return (my_rx(pile1, size1) && my_rx(pile2, size2));
}
