# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:27:53 by cofoundo          #+#    #+#              #
#    Updated: 2019/11/14 16:47:41 by cofoundo         ###   ########.fr        #
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
					ft_strtrim.c

BONUS			=   \
					ft_lstadd_back_bonus.c    \
					ft_lstadd_front_bonus.c    \
					ft_lstnew_bonus.c    \
					ft_lstlast_bonus.c    \
					ft_lstsize_bonus.c    \
					ft_lstdelone_bonus.c    \
					ft_lstclear_bonus.c	\
					ft_lstiter_bonus.c	\
					ft_lstmap_bonus.c

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
