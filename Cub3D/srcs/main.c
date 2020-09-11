/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/10 14:35:12 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_struct(t_list *parse, t_mlx *mlx)
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
	parse->i_map = 0;
	parse->spawn = 0;
	parse->save = NULL;
	parse->map = NULL;
	parse->north_path = NULL;
	parse->south_path = NULL;
	parse->west_path = NULL;
	parse->east_path = NULL;
	parse->sprite_path = NULL;
	mlx->ptr = NULL;
	return ;
}

int		main(int ac, char **av)
{
	t_list	parse;
	t_mlx	mlx;
	int		i;

	if (ac != 2 && ac != 3)
	{
		write(0, "number of argument to low or to great.\n", 39);
		return ;
	}
	if ((mlx.ptr = mlx_init()) == NULL)
	{
		write(0, "error in mlx_init.\n", 19);
		return ;
	}
	ft_init_struct(&parse, &mlx);
	if ((i = ft_get_next_line(&parse, av[1])) == 0)
		return ;
	if (i == -1)
	{
		write(0, "error during ft_strjoin.\n", 25);
		return ;
	}
	if (ft_parse(&parse, &mlx) == -1)
		return ;
	return ;
}
