/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:12 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/03 16:42:14 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if () : condition de sortie de recursive
** while () i++ : je laisse les plus petits a gauche
** while () j-- : je laisse les plus grands a droite
** je swap et replace donc les petits a gauche, les grands a droite
** je swap le pivot avec le dernier
** je recommence
*/

void	ft_quicksort(int *t, int start, int end)
{
	int	i;
	int	j;
	int pivot;

	if (start < end)
	{
		pivot = start;
		i = start;
		j = end;
		while (i < j)
		{
			while (t[i] <= t[pivot] && i < end)
				i++;
			while (t[j] > t[pivot])
				j--;
			if (i < j)
				ft_int_tab_swap(t, i, j);
		}
		ft_int_tab_swap(t, pivot, j);
		ft_quicksort(t, start, j - 1);
		ft_quicksort(t, j + 1, end);
	}
}
