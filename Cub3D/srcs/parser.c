/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:32:45 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/02 16:44:18 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** R resolution si plus grande que l ecran mettre par defaut la taille de l ecran premier terme x ensuite y
** NO texture nord
** SO texture sud
** WE texture ouest
** EA texture est
** F couleur du sol format RGB
** C couleur du plafond
** S texture du sprite
*/

int		ft_color(t_list *parse, int x)
{
	int	sign;

	sign = 0;
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

int		ft_floor_color(t_list *parse)
{
	int	count;

	count = 0;
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

int		ft_resolution(t_list *parse, long x, int y)
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

void	ft_texture(t_list *parse)
{
	if (parse->save[parse->i_save] == 'N')
		ft_north_texture(parse);
	if (parse->save[parse->i_save] == 'S')
		ft_south_texture(parse);
	if (parse->save[parse->i_save] == 'W')
		ft_west_texture(parse);
	if (parse->save[parse->i_save] == 'E')
		ft_east_texture(parse);
	return ;
}

int		ft_parse(t_list *parse)
{
	while (parse->save[parse->i_save])
	{
		if (parse->save[parse->i_save] == '1')
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
		}
		if (parse->save[parse->i_save] == 'R')
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
		}
		ft_texture(parse);
		if (parse->save[parse->i_save] == 'F')
			ft_floor_color(parse);
		if (parse->save[parse->i_save] == 'C')
			ft_ceiling_color(parse);
		if (parse->save[parse->i_save] == 'S')
			ft_sprite_texture(parse);
		parse->i_save++;
	}
	free(parse->save);
	return ;
}
