/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:23:51 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/10 14:41:58 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <libft.h>

typedef struct s_lst_int
{
	struct s_lst_int	*next;
	int		value;
	int id;
}		t_lst_int;

typedef struct s_stack
{
	t_lst_int	*a;
	t_lst_int	*b;
}		t_stack;

# define ERROR	-1
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

void	ft_pa(t_stack *t);
void	ft_pb(t_stack *t);

void	ft_rra(t_stack *t);
void	ft_rrb(t_stack *t);
void	ft_rrr(t_stack *t);

void	ft_ra(t_stack *t);
void	ft_rb(t_stack *t);
void	ft_rr(t_stack *t);

void	ft_sa(t_stack *t);
void	ft_sb(t_stack *t);
void	ft_ss(t_stack *t);

// int	ft_atoi(char const *s);
// int	ft_isdigit(int c);
int ft_strisdgit(char *str);
void	ft_lst_add_back(t_lst_int **alst, t_lst_int *new);

void	print_lst(t_lst_int *list);
void	print_lst_id(t_lst_int *list);
int	ft_isdouble(int *t, int end, int value);
#endif
