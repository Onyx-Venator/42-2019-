/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:49:08 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/04 14:11:05 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# define NUMBER 0
# define END 1
# define COL_RAS C_WHITE
# define COL_UP C_GREEN
# define COL_DOWN C_RED
# define COL_PUSH C_CYAN
# define COL_ROTATE C_YELLOW
# define STACK_A 0
# define STACK_B 1

typedef struct	s_prints
{
	int		size_max;
	int		size_a;
	int		size_b;
	char	*ope;
	int		i;
	int		a;
	int		b;
	char	*print_a;
	char	*print_b;
	char	*col_a;
	char	*col_b;
}				t_prints;

typedef struct	s_opt
{
	int		size;
	int		c;
	int		v;
}				t_opt;

typedef	struct	s_stack
{
	int				val;
	int				index;
	int				flag;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

/*
** main_shared.c
*/
int				are_sorted(int size, t_stack *a, t_stack *b);
int				*create_index_tab(t_stack **a);
int				check_input(int ac, char **av);
t_stack			*fill_stack(int ac, char **av);
int				free_all(char **line, t_stack **a, t_stack **b, char ***input);

/*
** operations.c
*/
void			rotate(t_stack **root);
void			reverse_rotate(t_stack **root);
void			swap(t_stack **root);
void			push(t_stack **receiving, t_stack **sending);

/*
** bonus_opt_v.c
*/
void			replace_to_print(t_stack **tmp, t_prints *dt, int stack);
int				print_stacks_no_color(t_stack *a, t_stack *b, int size);

/*
** bonus_opt_c.c
*/
void			print_legend(void);
void			print_stacks_color(t_stack *a, t_stack *b, int size, char *ope);

/*
** clst_print.c
*/
void			ft_print_int_tab(int *t, int size);
void			print_stack(t_stack *a, char *color1, char *color2);
int				print_stacks(t_stack *a, t_stack *b, int size, char *color);

/*
** clst_add_value.c
*/
void			clst_add_before(t_stack *elem, int val);
void			clst_add_after(t_stack *elem, int val);
void			clst_add_front(t_stack *root, int val);
void			clst_add_back(t_stack *root, int val);

/*
** clst_add_elem.c
*/
void			clst_add_elem_before(t_stack *elem, t_stack new);
void			clst_add_elem_after(t_stack *elem, t_stack new);
void			clst_add_elem_front(t_stack *root, t_stack new);
void			clst_add_elem_back(t_stack *root, t_stack new);

/*
** clst_general.c
*/
t_stack			*clst_create_root(void);
t_stack			*clst_hide_elem(t_stack *elem);
int				*clst_to_tab(t_stack *a, int size);
void			clst_clear_stack(t_stack *root);
void			clst_free_stack(t_stack **root);

/*
** clst_size.c
*/
int				clst_max_size(t_stack *a, t_stack *b);
int				clst_size(t_stack *root);

#endif
