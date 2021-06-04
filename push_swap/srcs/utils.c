/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:50:02 by anonymou          #+#    #+#             */
/*   Updated: 2021/06/04 12:12:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_isdigit(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
      i++;
    else
      return (0);
  }
  return (1);
}

int	ft_atoi(char *str)
{
	int i;
	int j;
	int n;

	i = -1;
	j = 1;
	n = 0;
	while (str[++i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
	|| str[i] == '\v' || str[i] == '\f')
		;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[++i - 1] == '-')
			j *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + str[++i - 1] - '0';
	return (n * j);
}
