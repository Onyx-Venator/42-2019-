# *** NAME - CC - FLAGS ****************************************************** #

NAME					= 	minishell

CC						= 	clang

CFLAGS					= 	-Wall -Wextra -Werror -I includes/ \
							-I libft/includes/ -I libftprintf/includes/ \

BONUS_FLAG				= 	0

TESTER_FLAG				= 	0

INC_LIB						= 	-I libft -I libftprintf
LIB							= 	-L libft -lft -L libftprintf \
								-lftprintf -lc -lncurses\



# *** PROJECT HEADER ********************************************************* #

HDIR					=	$(addprefix -I, $(HEADER_DIR))

HEAD					=	$(addprefix $(HEADER_DIR), $(HEADER))

HEADER_DIR				=	\
							./includes/

HEADER							=	\
									color_shell.h \
									libft_lst.h \
									minishell.h \
									minishell_builtins.h \
									minishell_ast_construction.h \
									minishell_termcaps.h \
									minishell_ast_execution.h \
									minishell_variables.h \

# *** SRCS ******************************************************************* #

SRCS_DIR					=	./srcs/

SRCS_LIST					=	\
							$(AST_CONSTRUCTION) \
							$(AST_EXECUTION) \
							$(BUILTINS) \
							$(EXPANSION) \
							$(TERMCAPS) \
							$(VARIABLES) \
							$(UTILS) \
							$(MAIN) \

AST_CONSTRUCTION			=	\
							ast_construction/ast_lexing.c \
							ast_construction/ast_lexing_check_error.c \
							ast_construction/ast_lexing_redir_tokens.c \
							ast_construction/ast_lexing_split_tokens.c \
							ast_construction/ast_lexing_tok_tab_functions.c \
							ast_construction/ast_parsing.c \
							ast_construction/ast_parsing_check_sep.c \
							ast_construction/ast_parsing_node_functions.c \

AST_EXECUTION				=	\
							ast_execution/ast_exec_fork.c \
							ast_execution/ast_execute_cmd.c \
							ast_execution/ast_execution.c \
							ast_execution/ast_process_cmd.c \
							ast_execution/ast_process_pipe.c \
							ast_execution/ast_redirections.c \
							ast_execution/ast_utils.c \

BUILTINS					=	\
							builtins/builtins_cd.c \
							builtins/builtins_cd_utils.c \
							builtins/builtins_env.c \
							builtins/builtins_exec.c \
							builtins/builtins_init.c \

EXPANSION					=	\
							expansion/expansion.c \
							expansion/expansion_removal.c \
							expansion/expansion_var.c \
							expansion/expansion_var_char.c \
							expansion/expansion_var_no_quote.c \
							expansion/expansion_var_utils.c \

TERMCAPS					=	\
							termcaps/tc_buffer_edition.c \
							termcaps/tc_init.c \
							termcaps/tc_utils.c \

VARIABLES					=	\
							variables/var_create_del.c \
							variables/var_general.c \
							variables/var_get.c \
							variables/var_set.c \

UTILS						=	\
							utils/signals.c \
							utils/utils.c \

MAIN						=	\
							main/env.c \
							main/handle_keys.c \
							main/history.c \
							main/main.c \
							main/read_input.c \

SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# *** OBJS ******************************************************************* #

OBJS_DIR				=	./objs/

OBJS_LIST				=	$(patsubst %.c, %.o, $(SRCS_LIST))

OBJS					=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))



all: $(OBJS) $(SRCS) $(NAME)

$(NAME): $(OBJS) $(SRCS)
	@ make -C libft/
	@ make -C libftprintf/
	@ $(CC) $(CFLAGS) $(HDIR) $(OBJS) $(INC_LIB) $(LIB) -o $@


$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@ mkdir -p $(dir $@)
	@ $(CC) $(CFLAGS) $(HDIR) -D BONUS=$(BONUS_FLAG) $(INC_LIB) -c -o $@ $<

clean:
	make clean -C libft/
	make clean -C libftprintf/
	rm -rf $(OBJS_DIR)

fclean:
	make fclean -C libft/
	make fclean -C libftprintf/
	rm -f $(NAME)
	rm -rf $(OBJS_DIR)

re: fclean all

bonus:
	make fclean
	make -j BONUS_FLAG=1

.PHONY: all clean fclean re bonus
