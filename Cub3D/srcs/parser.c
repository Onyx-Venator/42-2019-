/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:32:45 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/31 16:05:48 by cofoundo         ###   ########.fr       */
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

void	ft_resolution(t_list *parse, long x)
{
	int	sign;

	sign = 0;
	parse->i_save++;
	while (parse->save[parse->i_save] == ' ')
		parse->i_save++;
	while (parse->save[parse->i_save] == '-')
		sign++;
	while (parse->save[parse->i_save] >= '0' &&
		parse->save[parse->i_save] <= '9')
	x = x * 10 + parse->save[parse->i_save++] - '0';
	if (sign % 2 != 0)
		x *= -1;
	return ;
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
				return ;
			}
			if (ft_check_map(parse) == -1)
			{
				write(0, "map is not valide.\n", 19);
				return ;
			}
		}
		if (parse->save[parse->i_save] == 'R')
		{
			parse->bin |= 1 << 2;
			ft_resolution(parse, parse->r_x);
			ft_resolution(parse, parse->r_y);
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
