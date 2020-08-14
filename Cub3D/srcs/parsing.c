/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:20:36 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/14 16:18:27 by cofoundo         ###   ########.fr       */
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

void	ft_parse(t_list *parse, char *config)
{
	int		i;
	int		fd;
	char	*buffer;

	i = -1;
	fd = open(config, O_RDONLY);
	if (fd = -1)
		return (0);
}
