# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:27:53 by cofoundo          #+#    #+#              #
#    Updated: 2020/01/18 13:18:32 by cofoundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME	=	libft.a

SRCS			=	\
					ft_isprint.c    \
					ft_putchar_fd.c    \
					ft_strlcat.c \
					ft_substr.c \
					ft_atoi.c \
					ft_itoa.c \
					ft_putendl_fd.c \
					ft_strlcpy.c \
					ft_tolower.c \
					ft_bzero.c \
					ft_memccpy.c \
					ft_putnbr_fd.c \
					ft_strlen.c \
					ft_toupper.c \
					ft_calloc.c \
					ft_memchr.c \
					ft_putstr_fd.c \
					ft_strmapi.c \
					ft_isalnum.c \
					ft_memcmp.c \
					ft_split.c \
					ft_strncmp.c \
					ft_isalpha.c \
					ft_memcpy.c \
					ft_strchr.c \
					ft_strnstr.c \
					ft_isascii.c \
					ft_memmove.c \
					ft_strdup.c \
					ft_strrchr.c \
					ft_isdigit.c \
					ft_memset.c \
					ft_strjoin.c \
					ft_strtrim.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstnew.c \
					ft_lstlast.c \
					ft_lstsize.c \
					ft_lstdelone.c \
					ft_lstclear.c \
					ft_lstiter.c \
					ft_lstmap.c \
					get_next_line.c \
					ft_verif.c

LIBR			=	includes

OBJS			=	${SRCS:.c=.o}

BONUSOBJS		=	${BONUS:.c=.o}

CC        = gcc

RM        = rm -f

AR        = ar rc

FLAGS    = -Wall -Werror -Wextra

$(NAME):	${OBJS}
			@${AR} ${NAME} ${OBJS}

$(NAME_BONUS):	${OBJS} ${BONUSOBJS}
				@${AR} ${NAME} ${BONUSOBJS}

all:	${NAME}

bonus:	${OBJS} ${BONUSOBJS}
	${AR} ${NAME} ${BONUSOBJS} ${OBJS}

%.o: %.c ${CC} ${FLAGS} -c -o $@ $< -I ${LIBR}

clean:
		@${RM} ${BONUSOBJS} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY : all clean fclean re bonus
