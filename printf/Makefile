# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/18 15:38:50 by cofoundo          #+#    #+#              #
#    Updated: 2020/01/23 12:20:14 by cofoundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS			=	\
					libft/ft_isprint.c    \
					libft/ft_putchar_fd.c    \
					libft/ft_strlcat.c \
					libft/ft_substr.c \
					libft/ft_atoi.c \
					libft/ft_itoa.c \
					libft/ft_putendl_fd.c \
					libft/ft_strlcpy.c \
					libft/ft_tolower.c \
					libft/ft_bzero.c \
					libft/ft_memccpy.c \
					libft/ft_putnbr_fd.c \
					libft/ft_strlen.c \
					libft/ft_toupper.c \
					libft/ft_calloc.c \
					libft/ft_memchr.c \
					libft/ft_putstr_fd.c \
					libft/ft_strmapi.c \
					libft/ft_isalnum.c \
					libft/ft_memcmp.c \
					libft/ft_split.c \
					libft/ft_strncmp.c \
					libft/ft_isalpha.c \
					libftft_memcpy.c \
					libft/ft_strchr.c \
					libft/ft_strnstr.c \
					libft/ft_isascii.c \
					libft/ft_memmove.c \
					libft/ft_strdup.c \
					libft/ft_strrchr.c \
					libft/ft_isdigit.c \
					libft/ft_memset.c \
					libft/ft_strjoin.c \
					libft/ft_strtrim.c \
					libft/ft_lstadd_back.c \
					libft/ft_lstadd_front.c \
					libft/ft_lstnew.c \
					libft/ft_lstlast.c \
					libft/ft_lstsize.c \
					libft/ft_lstdelone.c \
					libft/ft_lstclear.c \
					libft/ft_lstiter.c \
					libft/ft_lstmap.c \
					libft/get_next_line.c \
					libft/ft_verif.c \
					printf.c

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
