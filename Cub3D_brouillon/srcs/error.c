/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/11/14 09:39:25 by anonymous        ###   ########.fr       */
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
    else if (i = -5)
      write(0, "error in color of ceiling\n", 26);
    return ;
}
