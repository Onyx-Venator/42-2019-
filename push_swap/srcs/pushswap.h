/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:45 by anonymou          #+#    #+#             */
/*   Updated: 2021/06/10 14:58:58 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define  PUSHSWAP_H

# include <unistd.h>
# include <stdlib.c>

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
void	ft_lstadd_back(t_value **alst, t_value *new)

#endif
