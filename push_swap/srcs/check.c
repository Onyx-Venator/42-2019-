/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 21:26:39 by cofoundo          #+#    #+#             */
/*   Updated: 2021/09/03 16:42:41 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (-1);
	return (i);
}

int			ft_pos(t_value *a, int target)
{
	int		i;
	t_value	*tmp;

	tmp = a;
	i = 1;
	while (tmp->id != target)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	verif_doublon(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == -1)
				return (0);
			j++;
		}
	}
	return (1);
}

int	verif_len(char *str)
{
	int	i;

	i = 0;
	if (ft_atoiminmax(i, str) == 0)
		return (0);
	return (1);
}

int	ft_verif(int ac, char **av)
{
	int	i;

	i = 0;

	while (++i < ac)
	{
		if (ft_isdigit(av[i]) == 0)
			return (0);
		if (verif_len(av[i]) == 0)
			return (0);
	}
	if (verif_doublon(av) == 0)
		return (0);
	return (1);
}
