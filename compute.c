/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:58:38 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 15:55:41 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_a(int *pile1, int *pile2, char **buf, int r[3][5])
{
	if (r[0][1] > 1 && r[1][0] && !(r[1][1] || r[1][2]))
	{
		if (r[0][2] > 1 && r[2][0])
			return ((my_ss(pile1, pile2, r[0][1], r[0][2])
					&& !ff("SWAP C", "ss ", buf, r[0])) ? 0 : 1);
			return ((my_sx(pile1, r[0][1])
					&& !ff("SWAP A", "sa ", buf, r[0])) ? 0 : 1);
	}
	else if (r[0][1] > 1 && r[1][1])
	{
		if (r[0][2] > 1 && !r[2][0] && r[2][1])
			return ((my_rr(pile1, pile2, r[0][1], r[0][2])
					&& !ff("ROTATE C", "rr ", buf, r[0])) ? 0 : 1);
			return ((my_rx(pile1, r[0][1])
					&& !ff("ROTATE A", "ra ", buf, r[0])) ? 0 : 1);
	}
	else if (r[0][1] > 1 && r[1][2])
	{
		if (r[0][2] > 1 && !r[2][0] && r[2][2])
			return ((my_rrr(pile1, pile2, r[0][1], r[0][2])
					&& !ff("REVERSE C", "rrr ", buf, r[0])) ? 0 : 1);
			return ((my_rrx(pile1, r[0][1])
					&& !ff("REVERSE A", "rra ", buf, r[0])) ? 0 : 1);
	}
	return (-1);
}

static int	check_b(int *pile1, int *pile2, char **buf, int r[3][5])
{
	if (r[0][2] > 1 && r[2][0])
		return ((my_sx(pile2, r[0][2])
				&& !ff("SWAP B", "sb ", buf, r[0])) ? 0 : 1);
	else if (r[0][2] > 1 && r[2][1])
	{
		if (!r[1][0] && r[1][1])
			return ((my_rr(pile1, pile2, r[0][1], r[0][2])
					&& !ff("ROTATE C", "rr ", buf, r[0])) ? 0 : 1);
			return ((my_rx(pile2, r[0][2])
					&& !ff("ROTATE B", "rb ", buf, r[0])) ? 0 : 1);
	}
	else if (r[0][2] > 1 && r[2][2])
	{
		if (!r[1][0] && r[1][2])
			return ((my_rrr(pile1, pile2, r[0][1], r[0][2])
					&& !ff("REVERSE C", "rrr ", buf, r[0])) ? 0 : 1);
			return ((my_rrx(pile2, r[0][2])
					&& !ff("REVERSE B", "rrb ", buf, r[0])) ? 0 : 1);
	}
	else if ((r[0][1] && r[0][3] != r[0][1]) || !r[0][2])
		return ((my_px(pile2, pile1, r[0][2]++, r[0][1]--)
				&& !ff("PUSH B", "pb ", buf, r[0])) ? 0 : 1);
	else
		return ((my_px(pile1, pile2, r[0][1]++, r[0][2]--)
				&& !ff("PUSH A", "pa ", buf, r[0])) ? 0 : 1);
}

void		my_compute(int *pile1, int *pile2, int size, int opt)
{
	int		c;
	int		ret;
	char	*buf;
	int		r[3][5];

	r[0][4] = opt;
	my_init1(&c, r[0], size, &buf);
	while (++c && (r[0][3] = my_sort(pile1, r[0][1], size, -1)))
	{
		if (my_init2(pile1, pile2, r[0], r) && r[0][4] == 2)
			my_debug(pile1, pile2, r[0][1], r[0][2]);
		if ((ret = check_a(pile1, pile2, &buf, r)) == 0)
			return ;
		else if (ret == 1)
			continue ;
		if ((ret = check_b(pile1, pile2, &buf, r)) == 0)
			return ;
	}
	if (opt == 2)
		my_debug(pile1, pile2, r[0][1], r[0][2]);
	return (my_end(opt, c - 1, buf, **r - 1));
}
