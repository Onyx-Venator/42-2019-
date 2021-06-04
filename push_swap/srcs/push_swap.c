/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:20:58 by anonymou          #+#    #+#             */
/*   Updated: 2021/06/04 12:37:32 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int verif_len(char *str)
{
  int i;

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
  return (1);
}

int ft_verif(int ac, char **av)
{
  int i;

  i = 0;
  while (i < ac)
  {
    i++;
      if (verif_len(av[i]) == 0)
        return (0);
      if (ft_isdigit(av[i]) == 0)
        return (0);
  }
  return (1);
}

int init(t_stack stack, int ac, char **av)
{
  
}

int main(int ac, char **av)
{
  t_stack stack;
  t_value *a;
  t_value *b;

  if (ac == 1 || ft_verif(ac, av) == 0)
  {
    write (2, "Error\n", 6);
    return (0);
  }
  if (init(stack, ac, av) == 0)
  {
    write (2, "Error\n", 6);
    return (0);
  }
  //algo
  return ;
}
