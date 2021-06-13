# *** NAME - CC - FLAGS ****************************************************** #

NAME_CHECKER					=	checker

NAME_PUSH_SWAP					=	push_swap

CC						= 	clang

CFLAGS					= 	-Wall -Wextra -Werror -I includes/ \
							-I libft/includes/\

BONUS_FLAG				= 	0

TESTER_FLAG				= 	0

INC_LIB						= 	-I libft
LIB							= 	-L libft -lft -lc -lncurses\



# *** PROJECT HEADER ********************************************************* #

HDIR					=	$(addprefix -I, $(HEADER_DIR))

HEAD					=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR				=	\
							./includes/

HEADER							=	\
									push_swap.h \

# *** SRCS ******************************************************************* #

SRCS_DIR					=	./srcs/

SRCS_LIST					=	\
								$(MAIN_CHECKER) \
								$(OP) \
								$(UTILS) \

SRCS_LIST_PS				=	\
								$(MAIN_PS) \
								$(OP) \
								$(UTILS) \

MAIN_CHECKER				=	\
								main/main_checker.c \

MAIN_PS				=	\
								main/main_push_swap.c \

OP							=	\
								op/push_fct.c \
								op/reverse_rotate_fct.c \
								op/rotate_fct.c \
								op/swap_fct.c \

UTILS						=	\
								utils/ft_atoi.c \
								utils/ft_isdigit.c \
								utils/lst_add_back.c \
								utils/print_lst.c \

SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

SRCS_PS					= 	$(addprefix $(SRCS_DIR), $(SRCS_LIST_PS))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_LIST				=	$(patsubst %.c, %.o, $(SRCS_LIST))

OBJS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

OBJS_LIST_PS			=	$(patsubst %.c, %.o, $(SRCS_LIST_PS))

OBJS_PS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST_PS))

all: $(OBJS) $(OBJS_PS) $(SRCS) $(SRCS_PS) $(NAME_CHECKER) $(NAME_PUSH_SWAP)

$(NAME_CHECKER): $(OBJS) $(SRCS)
	@ make -C libft/
	@ $(CC) $(CFLAGS) $(HDIR) $(OBJS) $(INC_LIB) $(LIB) -o $@

$(NAME_PUSH_SWAP): $(OBJS_PS) $(SRCS_PS)
	@ make -C libft/
	@ $(CC) $(CFLAGS) $(HDIR) $(OBJS_PS) $(INC_LIB) $(LIB) -o $@

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(HDIR) -D BONUS=$(BONUS_FLAG) $(INC_LIB) -c -o $@ $<

clean:
	make clean -C libft/
	rm -rf $(OBJS_DIR)

fclean:
	make fclean -C libft/
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_PUSH_SWAP)
	rm -rf $(OBJS_DIR)

re: fclean all

bonus:
	make fclean
	make -j BONUS_FLAG=1

.PHONY: all clean fclean re bonus
