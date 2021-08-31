/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/31 13:52:03 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define  PUSHSWAP_H

# include <unistd.h>
# include <stdlib.c>

# define RA		1
# define RB		2
# define RR		3
# define RRA	4
# define RRB	5
# define RRR	6
# define PA		7
# define PB		8
# define SA		9
# define SB		10
# define SS		11
# define A		12
# define B		13
# define C		14
# define D		15

typedef struct	s_value
{
	t_value		*next;
	int	 		value;
	int	 		id;
	int			flag;
}				t_value;

typedef struct	s_stack
{
	t_value		*a;
	t_value		*b;
	int			start_chain;
	int			id_max;
	int			next_id;
	int			id;
	int			size_a;
	int			size_b;
	int			check;
	int			op;
}				t_stack;

void	ft_sa(t_stack *t);
void	ft_sb(t_stack *t);
void	ft_ss(t_stack *t);
void	ft_pa(t_stack *t);
void	ft_pb(t_stack *t);
void	ft_ra(t_stack *t);
void	ft_rb(t_stack *t);
void	ft_rr(t_stack *t);
void	ft_rra(t_stack *t);
void	ft_rrb(t_stack *t);
void	ft_rrr(t_stack *t);
int		ft_atoi(char *str);
int		ft_isdigit(char *str);
int		verif_len(char *str);
int		ft_verif(int ac, char **av);
int		ft_atoiminmax(int i, char *str);
int		verif_doublon(char **av);
void	ft_lstadd_back(t_value **alst, t_value *new);
void	add_id(t_value *a, int *j);
t_value	*ft_lstlast(t_value *lst);
int		ft_pos(t_value *a, int target);
void	ft_exec_op(int op, t_stack *stack, int nb_ope);
void	longer_chain(t_stack *stack);
void	id_max(t_stack *stack);
void	set_flags(t_stack *stack);
void	swap_stack(t_stack *stack);
int		end_stack(t_value *a);
int		ft_lstsize(t_list *lst);
int		get_next_id(t_value *a, int val);
int		get_stack_min(t_value *a);
int		get_stack_max(t_value *a);
void	search_case(t_stack *stack);
void	best_op(t_stack *stack);
void	search_op(t_stack *stack);
int		get_id(t_value *b, int val);
int		max(int i, int j);
int		min(int i, int j);
void	exec_op_n(t_stack *stac);
void	case_two(t_stack *stack);
void	case_three(t_stack *stack);
void	case_four(t_stack *s);
void	case_five(t_stack *s);
#endif
