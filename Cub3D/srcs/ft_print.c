/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:02:12 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/28 20:21:56 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_img(t_list *parse)
{
	int	np;
	int	sl;
	int	end;

	parse->bin = 0;
	parse->img.ptr = mlx_new_image(parse->mlx.ptr, parse->r_x, parse->r_y)
	parse->img.adr = (unsigned int *)mlx_get_data_addr(parse->img.ptr,
		&np, &sl, &end);

	return ;
}

void	ft_or_cam(t_list *parse)
{
	if (parse->inf_alg.or_spawn == 'N')
	{
		parse->inf_alg.cam_x = 0.5;
		parse->inf_alg.cam_y = 1.0;
	}
	if (parse->inf_alg.or_spawn == 'E')
	{
		parse->inf_alg.cam_x = 1.0;
		parse->inf_alg.cam_y = 0.5;
	}
	if (parse->inf_alg.or_spawn == 'S')
	{
		parse->inf_alg.cam_x = 0.5;
		parse->inf_alg.cam_y = -1.0;
	}
	if (parse->inf_alg.or_spawn == 'W')
	{
		parse->inf_alg.cam_x = -1.0;
		parse->inf_alg.cam_y = 0.5;
	}
}

void	format_color(t_list *parse)
{
	parse->inf_alg.f_color = parse->f_r * (256*256) + parse->f_g * 256
		+ parse->f_b;
	parse->inf_alg.c_color = parse->c_r * (256*256) + parse->c_g * 256
		+ parse->c_b;
}

void	ft_spawn(t_list *parse)
{
	parse->i_map = 0;
	while (parse->map[parse->i_map] != 'W' && parse->map[parse->i_map] != 'E'
	&& parse->map[parse->i_map] != 'S' && parse->map[parse->i_map] != 'N')
	{
		if (parse->map[parse->i_map] == '\n')
		{
			parse->inf_alg.pos_y++
			parse->inf_alg.pos_x = 0;
		}
		parse->i_map++;
		parse->inf_alg.pos_x++;
	}
	parse->info_alg.or_spawn = parse->map[parse->i_map];
	return ;
}

int		ft_print(t_list *parse)
{
	//deplacement sur minicarte de 0.3
	//un mur a distance minimale prend tout l ecran est correspond a 50%
	//de sa taille reelle
	//tout les calcules de proportions doivent ete fait selon une regle de 3
	//un sprite est plus petit qu'un mur donc empeche vision sur derriere lui
	//donc simuler opaciter du sprite
	//distance minimale 0.1

	format_color(parse);
	ft_or_cam(parse);
	if ((parse->mlx.ptr = mlx_new_window(parse->mlx.ptr, parse->r_x, parse->r_y,
		"cub3D")) == 0)
		return (-1);
	ft_spawn(parse);
	parse->img.ptr = ft_img(parse);
	if (gen_map(parse, 10) == -1)
		return (-1);
	mlx_put_image_to_window(parse->mlx.ptr, parse->win.ptr,
		parse->img.ptr, 0, 0);
	return (1);
}
