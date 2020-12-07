/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:20:48 by cofoundo          #+#    #+#             */
/*   Updated: 2020/12/07 15:47:04 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_texture(char *path, unsigned int **adr, t_list *all)
{
  void *tmp;
  int  fd;
  int  xpm[2];
  int  adr[3];

  if ((fd = open(path, O_RDONLY)) == -1)
    return (-1);
  clode(fd);
  tmp = mlx_xpm_to_image(all->mlx.ptr, &path, &xpm[0], &xpm[1]);
  if (tmp == NULL || xpm[0] != 64 || xpm[1] != 64)
    return (-1);
  path = (unsigned int *)mlx_get_data_addr(tmp, &adr[0], &adr[1], &adr[2]);
  free(tmp);
  return (1);
}

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
  if (check_texture(tmp, &all->utils.north_path, all) < 0)
    return (-3);
  free(tmp);
  return (i);
}

int parse_so(char *str, int i, t_list *all)
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
  if (check_texture(tmp, &all->utils.south_path, all) < 0)
    return (-3);
  free(tmp);
  return (i);
}

int parse_sprite(char *str, int i, t_list *all)
{
  char *tmp;
  int  j;

  i++;
  while (str[i] == ' ')
    i++;
  j = i;
  while (str[j] != ' ' && str[j] != '\n')
    j++;
  if (!(tmp = malloc(sizeof(char) * (j - i + 1))))
    return (-6);
  tmp[j - i] = '\0';
  j = 0;
  while (str[i] != ' ' && str[i] != '\n')
    tmp[j++] = str[i++];
  if (check_texture(tmp, &all->utils.sprite_path, all) < 0)
    return (-6);
  free(tmp);
  return (i);
}

int parse_we(char *str, int i, t_list *all)
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
    return (-7);
  tmp[j - i] = '\0';
  j = 0;
  while (str[i] != ' ' && str[i] != '\n')
    tmp[j++] = str[i++];
  if (check_texture(tmp, &all->utils.west_path, all) < 0)
    return (-7);
  free(tmp);
  return (i);
}

int parse_ea(char *str, int i, t_list *all)
{
  char  *tmp;
  int   j;

  i += 2;
  while (str[i] == ' ')
    i++;
  j = i;
  while (str[j] != ' ' && str[j] != '\n')
    j++;
  if (!(tmp = malloc(siweof(char) * (j - i + 1))))
    return (-8);
  tmp[j - i] = '\0';
  j = 0;
  while(str[i] != ' ' && str[i] != '\n')
    tmp[j++] = str[i++];
  if (check_texture(tmp, &all->utils.east_path, all) < 0)
    return (-7);
  free(tmp);
  return (i);
}
