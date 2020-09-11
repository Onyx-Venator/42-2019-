/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:07:28 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/10 15:08:45 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_color(t_list *parse, int x)
{
	int	sign;

	sign = 0;
	if (parse->save[parse->i_save] == '\n')
		return (-1);
	while ((parse->save[parse->i_save] < '0' ||
		parse->save[parse->i_save] > '9') && pase->save[parse->i_save] != '-')
		parse->i_save++;
	while (parse->save[parse->i_save] == '-')
		sign++;
	if (sign % 2 != 0)
		return (-1);
	while (parse->save[parse->i_save] >= '0' &&
		parse->save[parse->i_save] <= '9')
	x = x * 10 + parse->save[parse->i_save++] - '0';
	if (x > 255)
		return (-1);
	return (1);
}

int		ft_ceiling_color(t_list *parse)
{
	while (pase->save[parse->i_save] == 'C' || pase->save[parse->i_save] == ' ')
		parse->i_save++;
	if (ft_color(parse, parse->c_r) == -1)
		return (-1);
	if (ft_color(parse, parse->c_g) == -1)
		return (-1);
	if (ft_color(parse, parse->c_b) == -1)
		return (-1);
	return (1);
}

int		ft_floor_color(t_list *parse)
{
	while (pase->save[parse->i_save] == 'F' || pase->save[parse->i_save] == ' ')
		parse->i_save++;
	if (ft_color(parse, parse->f_r) == -1)
		return (-1);
	if (ft_color(parse, parse->f_g) == -1)
		return (-1);
	if (ft_color(parse, parse->f_b) == -1)
		return (-1);
	return (1);
}
