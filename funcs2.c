/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 14:00:40 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/14 14:51:50 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_rrx(int *pile, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = pile[i];
	while (i < size - 1)
	{
		pile[i] = pile[i + 1];
		i++;
	}
	pile[i] = tmp;
	return (1);
}

int	my_rrr(int *pile1, int *pile2, int size1, int size2)
{
	return (my_rrx(pile1, size1) && my_rrx(pile2, size2));
}

int	my_swap(int *pile, int size, int sens)
{
	if (size < 2)
		return (0);
	if (sens < 0)
		return (size && pile[size - 2] > pile[size - 1]);
	else
		return (size && pile[size - 2] < pile[size - 1]);
}

int	my_reverse(int *pile, int size, int sens)
{
	if (size < 2)
		return (0);
	if (sens < 0)
		return (pile[size - 1] < pile[0] && (size == 2 || pile[1] < pile[0]));
	else
		return ((pile[size - 1] < pile[0] || pile[size - 1] > pile[0])
				&& (size == 2 || pile[1] > pile[0]));
}

int	my_rotate(int *pile, int size, int sens)
{
	if (size < 2)
		return (0);
	if (sens < 0)
		return (pile[size - 1] < pile[0] && (size == 2 || pile[1] > pile[0]));
	else
		return (pile[size - 1] > pile[0] && (size == 2 || pile[1] < pile[0]));
}
