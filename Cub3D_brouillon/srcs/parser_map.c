/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:38:23 by anonymou          #+#    #+#             */
/*   Updated: 2020/12/08 15:19:50 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_map(char *str, int i, t_list *all)
{
  char  *prev_line;
  int   start;
  int   end;

  start = i;
  while ((str[i] == '1' || str[i] == '0' || str[i] == ' ' || str[i] == '2' ||
  str[i] == '\n') && str[i])
  {

  }
  copy_map(str, i, all);
  return (i);
}
