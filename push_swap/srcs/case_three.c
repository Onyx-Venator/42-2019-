/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:35:55 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/02 18:22:25 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	case_three(t_stack *stack)
{
	if (stack->a->id == 1 && stack->a->next->id == 3)
		write(1, "sa\nra\n", 6);
	else if (stack->a->id == 2 && stack->a->next->id == 1)
		write(1, "sa\n", 3);
	else if (stack->a->id == 2 && stack->a->next->id == 3)
		write(1, "rra\n", 4);
	else if (stack->a->id == 3 && stack->a->next->id == 1)
		write(1, "ra\n", 3);
	else if (stack->a->id == 3 && stack->a->next->id == 2)
		write(1, "sa\nrra\n", 7);
}
