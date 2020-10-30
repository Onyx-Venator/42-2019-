/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/10/27 17:14:20 by onix             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parse_no(char *str, int i, t_list *all)
{
  char  *tmp;
  int   j;

  i += 2;
  while (str[i] == ' ')
    i++;
  j = i;
  while (str[j] != ' ' && str[j] != '\n')
    j++;
  if (!(tmp = malloc(sizeof(char) * (j - i + 1))))
    return (-2);
  tmp[j - i] = '\0';
  j = 0;
  while (str[i] != ' ' && str[i] != '\n')
    tmp[j++] = str[i++];
  if (check_texture(tmp, all->utils.north_path) < 0)
    return (-2);
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
  return (i);
}

int init_parse(t_list *all)
{
  int i;

  i = 0;
  while (all->save[i] && i >= 0)
  {
    i = check_c(all->save, i, all);
    i++;
  }
  return (i);
}
