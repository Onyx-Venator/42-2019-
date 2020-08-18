/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 16:32:45 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/18 19:04:13 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** checker s il y une map fermer 1 mur 2 objet 0 vide caract N,S,E ou W pour le pt de spawn mettre le premier bit a 1
** R resolution si plus grande que l ecran mettre par defaut la taille de l ecran premier terme x ensuite y
** NO texture nord
** SO texture sud
** WE texture ouest
** EA texture est
** F couleur du sol format RGB
** C couleur du plafond
** S texture du sprite
*/

void	ft_parse(t_list *parse)
{
	while (parse->save[parse->i_save])
	{
		if (parse->save[parse->i_save] == '1')
			ft_map(parse);
		if (parse->save[parse->i_save] == 'R')
			ft_resolution(parse);
		if (parse->save[parse->i_save] == 'N')
			ft_north_texture(parse);
		if (parse->save[parse->i_save] == 'S')
			ft_south_texture(parse);
		if (parse->save[parse->i_save] == 'W')
			ft_west_texture(parse);
		if (parse->save[parse->i_save] == 'E')
			ft_east_texture(parse);
		if (parse->save[parse->i_save] == 'F')
			ft_floor_color(parse);
		if (parse->save[parse->i_save] == 'C')
			ft_
		parse->i_save++;
	}
}
