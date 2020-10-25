# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 19:34:08 by cofoundo          #+#    #+#              #
#    Updated: 2020/06/25 18:34:16 by cofoundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	Cub3D

SRCS			=

LIBR			=	includes

OBJS			=	${SRCS:.c=.o}

CC        = gcc

RM        = rm -f

AR        = ar rc

FLAGS    = -Wall -Werror -Wextra

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}

all:	${NAME}

%.o: %.c ${CC} ${FLAGS} -c -o $@ $< -I ${LIBR}

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re bonus
