# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jose-vda <jose-vda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/17 09:29:47 by jose-vda          #+#    #+#              #
#    Updated: 2025/07/16 18:27:33 by jose-vda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC	 = 	src/push_swap.c \
		src/less_than_five.c \
		src/radix.c \
		src/utils.c \
		src/parse_args.c \
		src/push_moves.c \
		src/rotate_moves.c \
		src/swap_moves.c \
		src/reverser_moves.c \
		src/stack_utils.c \

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I include

%.o: %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@


$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -o ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re