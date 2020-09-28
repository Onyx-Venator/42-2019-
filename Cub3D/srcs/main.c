/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/23 22:10:49 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_inf_alg(t_list *parse)
{
	parse->inf_alg.pos_x = 0;
	parse->inf_alg.pos_y = 0;
	parse->inf_alg.f_color = 0;
	parse->inf_alg.c_color = 0;
	parse->inf_alg.cam_x = 0;
	parse->inf_alg.cam_y = 0;
	parse->info_alg.or_spawn = 0;
	parse->info_alg.map = NULL;
	parse->info_alg.x_map = 0;
	parse->info_alg.y_map = 0;
	return ;
}

void	init_win(t_list *parse)
{
	parse->win.ptr = NULL;
	parse->win.x = 0;
	parse->win.y = 0;
	return ;
}

void	init_img(t_list *parse)
{
	parse->img.patr = NULL;
	parse->img.adr = 0;
	parse->img.x = 0;
	return ;
}

void	ft_init_struct(t_list *parse, t_mlx *mlx)
{
	parse->bin = 0;
	parse->r_x = 1920;
	parse->r_y = 1080;
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
	parse->mlx.ptr = NULL;
	init_inf_alg(parse);
	init_win(parse);
	init_img(parse);
	return ;
}

int		main(int ac, char **av)
{
	t_list	parse;
	t_mlx	mlx;
	t_alg	inf_alg;
	t_win	win;
	t_img	img;
	int		i;

	if (ac != 2 && ac != 3)
	{
		write(0, "number of argument to low or to great.\n", 39);
		return (-1);
	}
	if ((mlx.ptr = mlx_init()) == NULL)
	{
		write(0, "error in mlx_init.\n", 19);
		return (-1);
	}
	ft_init_struct(&parse);
	if ((i = ft_get_next_line(&parse, av[1])) == 0)
		return (-1);
	if (i == -1)
	{
		write(0, "error during ft_strjoin.\n", 25);
		return (-1);
	}
	if (ft_parse(&parse, &parse->mlx) == -1)
		return (-1);
	if (ft_print(&parse) == -1)
		return (-1);
	return (1);
}
