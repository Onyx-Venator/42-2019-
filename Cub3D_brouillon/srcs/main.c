/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 16:52:33 by cofoundo          #+#    #+#             */
/*   Updated: 2020/12/08 14:49:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_img(t_list *all)
{
	all->img.patr = NULL;
	all->img.adr = 0;
	all->img.x = 0;
	return ;
}

void	init_win(t_list *all)
{
	all->win.ptr = NULL;
	all->win.x = 0;
	all->win.y = 0;
	return ;
}

void	init_mlx(t_list *all)
{
	all->mlx.ptr = NULL;
	return ;
}

void	init_utils(t_list *all)
{
	all->utils.res_x = 0;
	all->utils.res_y = 0;
	all->utils.floor_color = 0;
	all->utils.ceiling_color = 0;
	all->utils.north_path = 0;
	all->utils.south_path = 0;
	all->utils.sprite_path = 0;
	all->utils.west_path = 0;
	all->utils.east_path = 0;
	all->utils.map = NULL;
	return ;
}

void	ft_init_struct(t_list *all)
{
	all->bin = 0;
	all->save = NULL;
	init_img(all);
	init_win(all);
	init_mlx(all);
	init_utils(all);
	return ;
}

int		main(int ac, char **av)
{
	t_list	all;
	t_mlx		mlx;
	t_win		win;
	t_img		img;
	t_utils	utils;
	int			i;

	if (ac != 2 && ac != 3)
	{
		write(0, "number of argument to low or to great.\n", 39);
		return (-1);
	}
	ft_init_struct(&all);
	if ((all.mlx.ptr = mlx_init()) == NULL)
	{
		write(0, "error in mlx_init.\n", 19);
		return (-1);
	}
	if ((i = ft_get_next_line(&all, av[1])) == 0 || i == -1)
	{
		if (i == -1)
			write(0, "error during ft_strjoin.\n", 25);
		return (-1);
	}
	if (init_parse(&all) < 0)
		return (-1);
	if (ft_print(&all) == -1)
		return (-1);
	return (1);
}
