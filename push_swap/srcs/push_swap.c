/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/06/10 15:07:28 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	verif_doublon(char **av)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (av[++i])
	{
		x = -1;
		j = i + 1;
		while (av[i][++x])
		{
			if ((av[i][x] == av[j][x]) && (x == 0))
			{
				while (av[i][x] && av[j][x] && (av[i][x] == av[j][x]))
					x++;
				if (!av[i][x] && !av[j][x])
					return (0);
			}
		}
	}
	return (1);
}

int	verif_len(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		while (str[i++])
		;
		if (i > 11)
		return (0);
	}
	else
	{
		while (str[i++])
		;
		if (i > 10)
		return (0);
	}
	if (ft_atoiminmax(i, str) == 0)
		return (0);
	return (1);
}

int	ft_verif(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		i++;
		if (ft_isdigit(av[i]) == 0)
		return (0);
		if (verif_len(av[i]) == 0)
			return (0);
	}
	if (verif_doublon(av) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	stack;
	t_value	tmp;
	int		i;

	i = 0;
	if (ac == 1 || ft_verif(ac, av) == 0)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	stack.a = NULL;
	stack.b = NULL;
	while (ac > ++i)
	{
		tmp = malloc(sizeof(t_value));
		if (tmp == NULL)
		{
			write (2, "Error\n", 6);
			return (0);
		}
		tmp->next = NULL;
		tmp->value = ft_atoi(av[i]);
		ft_lstadd_back(&(stack->a), tmp);
	}
	//id_demerde
	return ;
}