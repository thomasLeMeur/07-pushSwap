/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:32:55 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 14:47:06 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	t_uchar	*tmp;

	if (!(tmp = (t_uchar *)malloc(n * sizeof(t_uchar))))
		return (dest);
	i = 0;
	if (dest && src)
	{
		while (i < n)
		{
			tmp[i] = ((t_uchar*)src)[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			((t_uchar*)dest)[i] = tmp[i];
			i++;
		}
	}
	free(tmp);
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	ad1;
	size_t	ad2;
	void	*tmp;
	size_t	i;

	if (!dest || !src || !n)
		return (dest);
	tmp = &src;
	ad1 = *((size_t*)tmp);
	tmp = &dest;
	ad2 = *((size_t*)tmp);
	if ((ad1 <= ad2 && ad1 + n >= ad2) || (ad2 <= ad1 && ad2 + n >= ad1))
		return (ft_memmove(dest, src, n));
	i = 0;
	while (i < n)
	{
		((t_uchar*)dest)[i] = ((t_uchar*)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (s)
		while (i < n)
			((t_uchar*)s)[i++] = (t_uchar)c;
	return (s);
}

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	tmp = (void*)malloc((size) * sizeof(t_uchar));
	return ((!tmp) ? NULL : ft_memset(tmp, 0, size));
}

void	*ft_memrealloc(void *s, size_t old_n, size_t new_n)
{
	t_uchar	*tmp;

	if (!new_n || old_n == new_n)
		return (s);
	if ((tmp = (t_uchar*)ft_memalloc(new_n * sizeof(t_uchar))))
	{
		old_n = (size_t)FT_MIN(old_n, new_n);
		ft_memcpy(tmp, s, old_n);
		if (s)
			free(s);
		s = tmp;
	}
	return (tmp);
}
