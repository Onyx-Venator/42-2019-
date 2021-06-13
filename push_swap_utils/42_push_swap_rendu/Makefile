# *** NAME - CC - FLAGS ****************************************************** #

NAME_CHECKER				= 	checker
NAME_PUSHSWAP				= 	push_swap

CC							= 	clang

CFLAGS						= 	-Wall -Wextra -Werror

INC							= 	\
								-I libft \
								-I libft/includes/ \
								-I libftprintf \
								-I libftprintf/includes/

LIB							=	\
								-L libft -lft \
								-L libftprintf -lftprintf \
								-lc \
								-lncurses\

# *** PROJECT HEADER ********************************************************* #

HDIR						=	$(addprefix -I, $(HEADER_DIR))

HEAD						=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR					=	\
								./includes/

HEADER						=	\
								color_shell.h \
								checker.h \
								push_swap.h \

# *** SRCS_ALL ******************************************************************* #

SRCS_DIR					=	./srcs/

SRCS_LIST_SHARED					= 	\
								align_a.c\
								bonus_opt_c.c\
								bonus_opt_v.c\
								clean_a.c\
								clst_add_elem.c\
								clst_add_value.c\
								clst_general.c\
								clst_print.c\
								clst_size.c\
								exec.c\
								get.c\
								main_shared.c\
								merge_stacks.c\
								operations.c\
								sort.c\
								swap_a.c

SRCS_LIST_CHECKER				= 	main_checker.c

SRCS_LIST_PUSHSWAP				= 	main_push_swap.c

SRCS_ALL						=	\
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_SHARED)) \
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_CHECKER)) \
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_PUSHSWAP))

SRCS_SHARED						=	\
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_SHARED))

SRCS_CHECKER					=	\
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_CHECKER))

SRCS_PUSHSWAP				=	\
								$(addprefix $(SRCS_DIR), $(SRCS_LIST_PUSHSWAP))


# *** OBJS ******************************************************************* #

OBJS_DIR					=	./objs/

OBJS_LIST_SHARED					=	$(patsubst %.c, %.o, $(SRCS_LIST_SHARED))

OBJS_LIST_CHECKER				=	$(patsubst %.c, %.o, $(SRCS_LIST_CHECKER))

OBJS_LIST_PUSHSWAP				=	$(patsubst %.c, %.o, $(SRCS_LIST_PUSHSWAP))

OBJS_ALL						=	\
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_SHARED)) \
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_CHECKER)) \
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_PUSHSWAP))

OBJS_SHARED						=	\
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_SHARED))

OBJS_CHECKER					=	\
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_CHECKER))

OBJS_PUSHSWAP				=	\
								$(addprefix $(OBJS_DIR), $(OBJS_LIST_PUSHSWAP))


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(HDIR) $(INC) -c -o $@ $<

# *** RULES ****************************************************************** #

all: $(OBJS_ALL) $(SRCS_ALL) $(NAME_CHECKER) $(NAME_PUSHSWAP)

$(NAME_CHECKER): $(OBJS_HECKER) $(SRCS_CHECKER) $(OBJS_SHARED) $(SRCS_SHARED)
	@ make -C libft/
	@ make -C libftprintf/
	$(CC) $(CFLAGS) $(HDIR) $(OBJS_CHECKER) $(OBJS_SHARED) $(INC) $(LIB) -o $@

$(NAME_PUSHSWAP): $(OBJS_PUSHSWAP) $(SRCS_PUSHSWAP) $(OBJS_SHARED) $(SRCS_SHARED)
	@ make -C libft/
	@ make -C libftprintf/
	$(CC) $(CFLAGS) $(HDIR) $(OBJS_PUSHSWAP) $(OBJS_SHARED) $(INC) $(LIB) -o $@

clean:
	@ make clean -C libft/
	@ make clean -C libftprintf/
	@ rm -rf $(OBJS_DIR)

fclean: clean
	@ make fclean -C libft/
	@ make fclean -C libftprintf/
	@ rm -f $(NAME_CHECKER) $(NAME_PUSHSWAP)
	@ rm -rf $(OBJS_DIR)

re: fclean all
#norm:
#	norminette $(SRCS_ALL) $(HEADER)

.PHONY: all clean fclean re

