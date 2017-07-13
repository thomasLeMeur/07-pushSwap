# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tle-meur <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 14:47:01 by tle-meur          #+#    #+#              #
#    Updated: 2016/01/13 16:16:18 by tle-meur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

FLAGS		=	-Wall -Wextra -Werror

SRCS		=	main.c compute.c utilities1.c utilities2.c funcs1.c funcs2.c \
				libft.c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:
				gcc $(FLAGS) -c $(SRCS)
				gcc -o $(NAME) $(OBJS)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean $(NAME)

.PHONY		:	all clean fclean re
