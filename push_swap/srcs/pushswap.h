/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2021/06/27 23:13:30 by cofoundo         ###   ########.fr       */
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

typedef struct	s_value
{
	t_value		*next;
	int	 		value;
	int	 		id;
}				t_value;

typedef struct	s_stack
{
	t_value		*a;
	t_value		*b;
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
#endif
