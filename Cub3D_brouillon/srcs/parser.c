/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/11/14 09:56:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_color(char *str, int i, t_list *all, int color)
{
  int error;
  int tmp;

  if (str[i] == 'F')
    error = -4;
  if (str[i] == 'C')
    error = -5;
  i++;
  while (str[i] == ' ')
    i++;
  tmp = 0;
  return (i);
}

int check_c(char *str, int i, t_list *all)
{
  if (str[i] == 'R' && i >= 0)
  {
    all->bin |= 1 << 2;
    if ((i = parse_res(str, i, all)) < 0)
      parser_error(i);
  }
  if (str[i] == 'N' && str[i + 1] == 'O' && i >= 0)
  {
    all->bin |= 1 << 3;
    if ((i = parse_no(str, i, all)) < 0)
      parser_error(i);
  }
  if (str[i] == 'S' && str[i + 1] == 'O' && i >= 0)
  {
    all->bin |= 1 << 3;
    if ((i = parse_so(str, i, all)) < 0)
      parser_error(i);
  }
  if (str[i] == 'F' && i >= 0)
  {
    all->bin |= 1 << 4;
    if ((i = parse_color(str, i, all, &all->utils.floor_color)) < 0)
      parser_error(i);
  }
  return (i);
}

int init_parse(t_list *all)
{
  int i;

  i = 0;
  while (all->save[i] && i >= 0)
  {
    i = check_c(all->save, i, all);
    if (i < 0)
      return (i);
    i++;
  }
  return (i);
}
