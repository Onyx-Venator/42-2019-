/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_resolution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:30:26 by cofoundo          #+#    #+#             */
/*   Updated: 2020/10/27 16:31:09 by onix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_res(t_list *all)
{
  if (all->utils.res_x > RES_X_MAX)
    all->utils.res_x = RES_X_MAX;
  if (all->utils.res_y > RES_Y_MAX)
    all->utils.res_y = RES_Y_MAX;
  return ;
}

int ft_atoi(char *str, int i, t_list *all)
{
  while (str[i] >= '0' && str[i] <= '9')
    all->utils.res_x = all->utils.res_x * 10 + str[++i - 1] - '0';
  while (str[++i] == ' ')
    ;
  if (str[i] < '0' || str[i] > '9')
    return (-1);
  while (str[i] >= '0' && str[i] <= '9')
    all->utils.res_y = all->utils.res_y * 10 + str[++i - 1] - '0';
  return (i);
}

int parse_res(char *str, int i, t_list *all)
{
  while (str[++i] == ' ')
    ;
  if (str[i] < '0' || str[i] > '9')
    return (-1);
   i = ft_atoi(str, i, all);
  check_res(all);
  while (str[i] != '\n')
  {
      if (str[i] != ' ')
        return (-1);
      i++;
  }
  return (i);
}
