/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 11:15:17 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/10 14:44:38 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

int check_order(t_stack stack)
{
	t_lst_int *tmp;

	if (stack.b)
		return	(0);
	tmp = stack.a;
	if (!tmp)
		return (1);
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->value < tmp->next->value)
				;
			else
				return (0);
		}
		tmp = tmp -> next;
	}
	return (1);
}

int ft_parse_op(char *str)
{
	if (ft_strcmp(str, "ra") == 0)
		return (RA);
	else if (ft_strcmp(str, "rb") == 0)
		return (RB);
	else if (ft_strcmp(str, "rr") == 0)
		return (RR);
	else if (ft_strcmp(str, "rra") == 0)
		return (RRA);
	else if (ft_strcmp(str, "rrb") == 0)
		return (RRB);
	else if (ft_strcmp(str, "rrr") == 0)
		return (RRR);
	else if (ft_strcmp(str, "pa") == 0)
		return (PA);
	else if (ft_strcmp(str, "pb") == 0)
		return (PB);
	else if (ft_strcmp(str, "sa") == 0)
		return (SA);
	else if (ft_strcmp(str, "sb") == 0)
		return (SB);
	else if (ft_strcmp(str, "ss") == 0)
		return (SS);
	return (ERROR);
}

void ft_exec_op(int op, t_stack *stack)
{
	if (op == ERROR)
		return ;
	else if (op == RA)
		ft_ra(stack);
	else if (op == RB)
		ft_rb(stack);
	else if (op == RR)
		ft_rr(stack);
	else if (op == RRA)
		ft_rra(stack);
	else if (op == RRB)
		ft_rrb(stack);
	else if (op == RRR)
		ft_rrr(stack);
	else if (op == PA)
		ft_pa(stack);
	else if (op == PB)
		ft_pb(stack);
	else if (op == SA)
		ft_sa(stack);
	else if (op == SB)
		ft_sb(stack);
	else if (op == SS)
		ft_ss(stack);
}

void	ft_exec_op_print(int op, t_stack *stack)
{
	ft_exec_op(op, stack);
	if (op == RA)
		printf("ra\n");
	else if (op == RB)
		printf("rb\n");
	else if (op == RR)
		printf("rr\n");
	else if (op == RRA)
		printf("rra\n");
	else if (op == RRB)
		printf("rrb\n");
	else if (op == RRR)
		printf("rrr\n");
	else if (op == PA)
		printf("pa\n");
	else if (op == PB)
		printf("pb\n");
	else if (op == SA)
		printf("sa\n");
	else if (op == SB)
		printf("sb\n");
	else if (op == SS)
		printf("ss\n");
}

int main(int argc, char **argv)
{
	int		i;
	t_stack	stack;
	t_lst_int	*tmp;
	int *t;

	i = 1;
	stack.a = NULL;
	stack.b = NULL;
	// printf("%s\n", argv[2]);
	while (argc > i)
	{
		if (!ft_strisdgit(argv[i]))
		{
			printf("error is digit\n");
			// free lst;
			return (0);
		}
		tmp = malloc(sizeof(t_lst_int));
		if (!tmp)
		{
			// free lst;*
			printf("error malloc\n");
			return (0);
		}
		tmp->value = ft_atoi(argv[i]);
		tmp->next = NULL;
		ft_lst_add_back(&(stack.a), tmp);
		i++;
	}
	t = malloc(sizeof(int) * (i));
	if (t == NULL)
	{
		// free lst;
		printf("error malloc\n");
		return (0);
	}
	i = 1;
	while (argc > i)
	{
		if (ft_isdouble(t,i - 1,ft_atoi(argv[i])))
		{
			printf("error double digit\n");
			return (0);
		}
		t[i - 1] = ft_atoi(argv[i]);
		i++;
	}

	char *str;
	int ret;
	print_lst(stack.a);
	if (check_order(stack))
	{
		printf("ok\n");
		return (0);
	}
	ret = get_next_line(1,&str);
	while (ret > 0)
	{
		ret = ft_parse_op(str);
		ft_exec_op(ret, &stack);
		if (ret == -1)
		{
			printf("error op\n");
			return (0);
		}
		if (check_order(stack))
		{
			printf("ok\n");
			return (0);
		}
		ret = get_next_line(1,&str);
	}
	return (0);
}
