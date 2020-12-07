/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/12/07 15:37:43 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_error(int i)
{
    if (i == -1)
      write(0, "error of resolution in map.cub\n", 31);
    else if (i == -2)
      write(0, "error in path of north texture\n", 31);
    else if (i == -3)
      write(0, "error in path of south texture\n", 31);
    else if (i == -4)
      write(0, "error in color of floor\n", 25);
    else if (i == -5)
      write(0, "error in color of ceiling\n", 26);
    else if (i == -6)
      write(0, "error in path of sprite\n", 24);
    else if (i == -7)
      write(0, "error in path of west texture\n", 30);
    else if (i == -8)
      write(0, "error in path of east texture\n", 30);
    return ;
}
