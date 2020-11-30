/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 09:00:30 by anonymou          #+#    #+#             */
/*   Updated: 2020/11/30 09:03:26 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int color(char *str, int i, int color)
{
  if (str[i] < '0' || str > '9')
    return (-1);
  while (str[i] >= '0' && str[i] <= '9')
    color = color * 10 + str[++i - 1] - '0';
  return (color);
}

int parse_color(char *str, int i, t_list *all, int color)
{
  int error;
  int tmp;

  if (str[i] == 'F')
    error = -4;
  if (str[i] == 'C')
    error = -5;
  i++;
  tmp = 0;
  while (++tmp <= 3)
  {
    while (str[i] == ' ')
      i++;
    if ((color = color(str, i, color) < 0))
      return (error);
  }
  return (i);
}
