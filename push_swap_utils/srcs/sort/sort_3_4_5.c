/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:13:08 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/04 16:49:21 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sort_3(t_stack *stack)
{
	int id[3];
	
	id[0] = stack->a->id;
	id[1] = stack->a->next->id;
	id[2] = stack->a->next->next->id;
	if (id[0]< id[1] && id[1] > id[2] && id[2] > id[0])
	 {
		ft_exec_op_print(SA, stack);
		ft_exec_op_print(RA, stack);
	 }
	 else if (id[0] > id[1] && id[1] < id[2] && id[2] > id[0])
	 	ft_exec_op_print(SA, stack);
	 else if (id[0] < id[1] && id[1] > id[2] && id[2] < id[0])
	 	ft_exec_op_print(RRA, stack);
	 else if (id[0] > id[1] && id[1] < id[2] && id[2] < id[0])
	 	ft_exec_op_print(RA, stack);
	 else if (id[0] > id[1] && id[1] > id[2] && id[2] < id[0])
	{
		 ft_exec_op_print(SA, stack);
		 ft_exec_op_print(RRA, stack);
  	}
}

void	sort_4(t_stack *stack)
{
	int	i;
	int j;
	int t[4];
	
	i = 0;
	j = 0;
	t[0] = stack->a->id;
	t[1] = stack->a->next->id;
	t[2] = stack->a->next->next->id;
	t[3] = stack->a->next->next->next->id;
	while (prog_stack_4[i]->stack[0] == t[0] &&
		prog_stack_4[i]->stack[1] == t[1] &&
		prog_stack_4[i]->stack[2] == t[2] &&
		prog_stack_4[i]->stack[3] == t[3])
		i++
	while (prog_stack_4[i]->prog[j])
	{
		ft_exec_op_print(ft_parse_op(prog_stack_4[i]->prog[j]), stack);
		j++;
	}
}

void	sort_5(t_stack *stack)
{
	int	i;
	int j;
	int t[5];
	
	i = 0;
	j = 0;
	t[0] = stack->a->id;
	t[1] = stack->a->next->id;
	t[2] = stack->a->next->next->id;
	t[3] = stack->a->next->next->next->id;
	t[4] = stack->a->next->next->next->next->id;
	while (!(prog_stack_5[i]->stack[0] == t[0] &&
		prog_stack_5[i]->stack[1] == t[1] &&
		prog_stack_5[i]->stack[2] == t[2] &&
		prog_stack_5[i]->stack[3] == t[3] &&
		prog_stack_5[i]->stack[4] == t[4]))
		i++
	while (prog_stack_5[i]->prog[j])
	{
		ft_exec_op_print(ft_parse_op(prog_stack_5[i]->prog[j]), stack);
		j++;
	}
}


