# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vaferrei <vaferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 20:47:53 by vaferrei          #+#    #+#              #
#    Updated: 2021/10/02 17:21:32 by vaferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT 	= ./libft/libft.a

NAME	= libftprintf.a

SRCS	= 	ft_printf.c \
			ft_make_char.c \
			ft_make_decimal.c \
			ft_make_undecimal.c \
			ft_make_hexa.c \
			ft_make_pointer.c \
			ft_treat_char.c \
			ft_treat_decimal.c \
			ft_treat_undecimal.c \
			ft_treat_hexa.c \
			ft_treat_pointer.c \
			ft_treat_flags.c \


OBJS	= ${SRCS:.c=.o}


CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			$(MAKE) -C ./libft
			cp libft/libft.a $(NAME)
			ar -rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
		$(MAKE) clean -C ./libft
		rm -f ${OBJS}
		rm -f ${BOBJS}

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -f ${NAME}

re: fclean all

bonus: re


test: all
	${CC} main.c libftprintf.a libft/libft.a -o teste
	./teste

.PHONY: all, bonus, clean, fclean, re
