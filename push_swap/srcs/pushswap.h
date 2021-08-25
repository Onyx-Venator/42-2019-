/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2021/08/23 13:24:29 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define  PUSHSWAP_H

# include <unistd.h>
# include <stdlib.c>

# define RA		1
# define RB		2
# define RR		4
# define RRA	8
# define RRB	16
# define RR		32
# define PA		64
# define PB		128
# define SA		256
# define SB		512
# define SS		1024

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
void	ft_exec_op(int op, t_stack *stack);
void	longer_chain(t_stack *stack);
void	id_max(t_stack *stack);
void	set_flags(t_stack *stack);
void	swap_stack(t_stack *stack);
int		end_stack(t_value *a);
int		ft_lstsize(t_list *lst);
int		get_next_id(t_value *a, int val);
int		get_stack_min(t_value *a);
int		get_stack_max(t_value *a);
#endif
