/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymou <anonymou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:38:23 by anonymou          #+#    #+#             */
/*   Updated: 2021/01/25 11:49:23 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int alloc_line(char *str, int j, int end, t_list *all)
{
  int i;
  int n;
  int x;

  i = 0;
  n = 0;
  x = j;
  while (str[x++] != '\n')
    i++;
  if (!(all->utils.map[n] = malloc(sizeof(char) * (i + 1))))
    return (-1);
  all->utils.map[n][i] = '\0';
  i = 0;
  while (str[j] != '\n')
    all->utils.map[n][i++] = str[j++];
  if (check_first_line(all->utils.map[n]) < 0)
    return (-1);
  j++;
  while (j < end)
  {
    n++;
    x = j;
    while (str[x++] != '\n')
      i++;
    if (!(all->utils.map[n] = malloc(sizeof(char) * (i + 1))))
      return (-1);
    all->utils.map[n][i] = '\0';
    i = 0;
    while (str[j] != '\n')
      all->utils.map[n][i++] = str[j++];
    if (check_line(all->utils.map[n], all->utils.map[n - 1]) < 0)
      return (-1);
    j++;
  }
  return (1);
}

int copy_map(char *str, int start, int end, t_list *all)
{
  int i;
  int j;

  j = start;
  i = 0;
  while (j < end)
  {
    if (j == '\n')
      i++;
    j++;
  }
  if (!(all->utils.map = malloc(sizeof(char*) * (i + 1))))
    return (-1);
  all->utils.map[i] = '\0';
  j = start;
  if ((j = alloc_line(str, j, end, all) < 0))
    return (-1);
  if (check_last_line(i - 1, all) < 0)
    return (-1);
  return (1);
}

int parse_map(char *str, int i, t_list *all)
{
  int   start;
  int   end;

  start = i;
  end = i;
  while ((str[end] == '1' || str[end] == '0' || str[end] == ' ' ||
  str[end] == '2' || str[end] == '\n') && str[end])
  {
    end++;
  }
  if (copy_map(str, start, end, all) < 0)
    return (-9);
  if (check_map < 0)
    return (-9);
  return (i);
}
