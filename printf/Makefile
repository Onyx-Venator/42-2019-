# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/16 19:34:08 by cofoundo          #+#    #+#              #
#    Updated: 2020/06/24 17:53:43 by cofoundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libftprintf.a

SRCS			=	\
					buffer.c	\
					flag_c.c	\
					flag_d_utils.c	\
					flag_d.c	\
					flag_p_utils.c	\
					flag_p.c	\
					flag_s.c	\
					flag_u.c	\
					flag_x_utils.c	\
					flag_x.c	\
					ft_printf.c	\
					parsing_utils.c	\
					parsing.c	\
					utils.c	\
					flag_u_utils.c

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

.PHONY : all clean fclean re
