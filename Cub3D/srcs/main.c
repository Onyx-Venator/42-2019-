/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/18 17:04:20 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_t_parse(t_list *parse)
{
	parse->bin = 0;
	parse->r_x = 0;
	parse->r_y = 0;
	parse->f_r = 0;
	parse->f_g = 0;
	parse->f_b = 0;
	parse->c_r = 0;
	parse->c_g = 0;
	parse->c_b = 0;
	parse->i_save = 0;
	save = NULL;
	return ;
}

int		main(int ac, char **av)
{
	t_list	parse;
	int		i;

	ft_init_t_parse(&parse);
	if ((i = ft_get_next_line(&parse, av[1])) == 0)
		return ;
	if (i == -1)
	{
		write(0, "error during ft_strjoin\n", 24);
		return ;
	}
	if (!(ft_parse(&parse)))
		return ;
	return ;
}
