/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 13:53:23 by tle-meur          #+#    #+#             */
/*   Updated: 2016/01/13 15:31:24 by tle-meur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define FT_MIN( x, y )	( ( (x) > (y) ) ? (y) : (x) )

typedef unsigned char	t_uchar;

void	my_compute(int *pile1, int *pile2, int size, int opt);

/*
**	funcs1.c
*/
int		my_sx(int *pile, int size);
int		my_rx(int *pile, int size);
int		my_ss(int *pile1, int *pile2, int size1, int size2);
int		my_px(int *pile1, int *pile2, int size1, int size2);
int		my_rr(int *pile1, int *pile2, int size1, int size2);

/*
**	funcs2.c
*/
int		my_rrx(int *pile, int size);
int		my_swap(int *pile, int size, int sens);
int		my_rotate(int *pile, int size, int sens);
int		my_reverse(int *pile, int size, int sens);
int		my_rrr(int *pile1, int *pile2, int size1, int size2);

/*
**	libft.c
*/
void	*ft_memalloc(size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memrealloc(void *s, size_t old_n, size_t new_n);

/*
**	utilities1.c
*/
void	my_putnbr(int nb);
int		my_strcmp(char *s1, char *s2);
int		my_quit(int **pile1, int **pile2);
int		my_sort(int *pile, int size, int real_size, int sens);
void	my_debug(int *pile1, int *pile2, int size1, int size2);

/*
**	utilities2.c
*/
size_t	my_strlen(const char *s);
void	my_end(int opt, int hits, char *buf, int size);
void	my_init1(int *c, int *s, int size, char **buf);
int		ff(char *debug, char *text, char **buf, int *len);
int		my_init2(int *pile1, int *pile2, int *s, int r[3][5]);

#endif
