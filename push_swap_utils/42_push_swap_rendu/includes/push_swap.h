/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:49:00 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:49:04 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"
# include "libftprintf.h"
# include <stdio.h>
# include "color_shell.h"
# include "get_next_line.h"
# include "checker.h"

# define SUCCESS 0
# define ERROR 1

# define CASE_A 1
# define CASE_B 2
# define CASE_C 3
# define CASE_D 4

typedef struct	s_case
{
	int	val;
	int	case_nb;
	int	ope_necess;
	int	i;
	int	j;
	int	size_a;
	int	size_b;
	int	half_a;
	int	half_b;
}				t_case;

/*
** get.c
*/
int				get_index(t_stack *b, int val);
int				get_stack_index(t_stack *a, int val);
int				get_stack_min(t_stack *root);
int				get_stack_max(t_stack *root);
int				get_next_index(t_stack *a, int val);

/*
** exec.c
*/
int				is_instruction(char *line);
void			exec_one_ope(char *line, t_stack *a, t_stack *b);
int				exec_ope(char *ope, t_stack **a, t_stack **b, int times);

/*
** merge_stacks.c
*/
void			merge_stacks(t_stack **a, t_stack **b);

/*
** swap_a
*/
int				should_swap_a(t_stack *a, t_stack *b);

/*
** clean_a
*/
void			fill_list_index(t_stack **a, int *t, int size);
int				count_flags(t_stack *a, int flag);
void			add_best_flags(t_stack **a);
void			clean_a(t_stack **a, t_stack **b);

/*
** align_a
*/
void			align_a(t_stack **a, t_stack **b);

/*
** sort.c
*/
void			sort_3(t_stack **a, t_stack **b);
void			sort_4(t_stack **a, t_stack **b);
void			sort_5(t_stack **a, t_stack **b);

/*
** libft.c
*/
/*
** long	ft_atoi_long(char const *s);
** char	**ft_tabdup(char **t);
** int				ft_free_tab(char ***t);
** int		ft_tablen(char **t);
** void	ft_quicksort(int *t, int start, int end);
** void	ft_print_int_tab(int *t, int size);
** int		ft_max(int i, int j);
** int		ft_min(int i, int j);
*/

#endif
