/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:32:45 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/23 19:10:40 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_resolution(t_list *parse, int x, int y)
{
	int	sign;

	sign = 0;
	while (parse->save[parse->i_save] == ' ' ||
		parse->save[parse->i_save] == 'R')
		parse->i_save++;
	while (parse->save[parse->i_save] == '-')
		sign++;
	if (sign % 2 != 0)
		return (-1);
	while (parse->save[parse->i_save] >= '0' &&
		parse->save[parse->i_save] <= '9')
	x = x * 10 + parse->save[parse->i_save++] - '0';
	if (x > y)
		x = y;
	return (1);
}

int		norm_map(t_list *parse)
{
	if (ft_map(parse) == -1)
	{
		write(0, "error in malloc map.\n", 21);
		return (-1);
	}
	if (ft_check_map(parse) == -1)
	{
		write(0, "map is not valide.\n", 19);
		return (-1);
	}
	return (1);
}

int		norm_reso(t_list *parse)
{
	if (ft_resolution(parse, parse->r_x, 1920) == -1)
	{
		write(0, "resolution x is not valide.\n", 28);
		return (-1);
	}
	if (ft_resolution(parse, parse->r_y, 1080))
	{
		write(0, "resolution y is not valide.\n", 28);
		return (-1);
	}
	return (1);
}

int		norm_color(t_list *parse)
{
	if (parse->save[parse->i_save] == 'F')
	{
		if (ft_floor_color(parse) == -1)
		{
			write(0, "color of floor is not valide.\n", 30);
			return (-1);
		}
	}
	if (parse->save[parse->i_save] == 'C')
	{
		if (ft_ceiling_color(parse) == -1)
		{
			write(0, "color of ceiling is not valide.\n", 32);
			return (-1);
		}
	}
	return (1);
}

int		ft_parse(t_list *parse, t_mlx *mlx)
{
	while (parse->save[parse->i_save])
	{
		if (parse->save[parse->i_save] == '1')
		{
			if (norm_map(parse) == -1)
				return (-1);
		}
		if (parse->save[parse->i_save] == 'R')
		{
			if (norm_reso(parse) == -1)
				return (-1);
		}
		if (texture(parse, mlx) == -1)
			return (-1);
		if (norm_color(parse) == -1)
			return (-1);
		parse->i_save++;
	}
	free(parse->save);
	return (1);
}
