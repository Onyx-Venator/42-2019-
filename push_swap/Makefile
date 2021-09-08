# *** NAME - CC - FLAGS ****************************************************** #

NAME					= 	pushswap

CC						= 	clang

CFLAGS					= 	-Wall -Wextra -Werror -I includes/ \

BONUS_FLAG				= 	0

TESTER_FLAG				= 	0

LIB							= 	 -lc -lncurses\



# *** PROJECT HEADER ********************************************************* #

HDIR					=	$(addprefix -I, $(HEADER_DIR))

HEAD					=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR				=	\
							./includes/

HEADER							=	\
									color_shell.h \
									pushswap.h \

# *** SRCS ******************************************************************* #

SRCS_DIR					=	./srcs/

SRCS_LIST					=	\
							$(PUSHSWAP) \

PUSHSWAP					=	\
							algo.c \
							case_five_utils.c \
							case_five.c \
							case_four.c \
							case_three.c \
							case_two.c \
							check.c \
							five_utils.c \
							get.c \
							id.c \
							lstfunction.c \
							push_swap.c \
							push.c \
							revrotate.c \
							rotate.c \
							stack_utils.c \
							stack.c \
							swap.c \
							utils.c \

SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_LIST				=	$(patsubst %.c, %.o, $(SRCS_LIST))

OBJS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))



all: $(OBJS) $(SRCS) $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@ $(CC) $(CFLAGS) $(HDIR) $(OBJS) $(INC_LIB) $(LIB) -o $@


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(HDIR) -D BONUS=$(BONUS_FLAG) $(INC_LIB) -c -o $@ $<

clean:
	rm -rf $(OBJS_DIR)

fclean:
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

bonus:
	make fclean
	make -j BONUS_FLAG=1

.PHONY: all clean fclean re bonus
