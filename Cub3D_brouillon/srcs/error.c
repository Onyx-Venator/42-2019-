/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/11/02 14:12:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parser_error(int i)
{
    if (i == -1)
      write(0, "error of resolution in map.cub\n", 31);
    if (i == -2)
      write(0, "error in path of north texture\n", 31);
    if (i == -3)
      write(0, "error in path of south texture\n", 31);
    return ;
}
