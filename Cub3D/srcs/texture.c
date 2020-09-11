/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:20:39 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/10 15:29:02 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_texture(t_list *parse, char *path, t_mlx *mlx)
{
	parse->i_save++;
	while (parse->save[parse->i_save] == ' ')
		parse->i_save++;
}

int		texture_next(t_list *parse, t_mlx *mlx)
{
	if (parse->save[parse->i_save] == 'W')
	{
		if (ft_texture(parse, parse->west_path, mlx) == -1)
		{
			write(0, "error in west path.\n", 20);
			return (-1)
		}
	}
	if (parse->save[parse->i_save] == 'E')
	{
		if (ft_texture(parse, parse->east_path, mlx) == -1)
		{
			write(0, "error in east path.\n", 20);
			return (-1);
		}
	}
	if (parse->save[parse->i_save] == 'S')
	{
		if (ft_texture(parse, parse->sprite_path, mlx) == -1)
		{
			write(0, "error in texture path.\n", 22);
			return (-1);
		}
	}
	return (1);
}

int		texture(t_list *parse, t_mlx *mlx)
{
	if (parse->save[parse->i_save] == 'N')
	{
		if (ft_texture(parse, parse->north_path, mlx) == -1)
		{
			write(0, "error in north path.\n", 21);
			return (-1);
		}
	}
	if (parse->save[parse->i_save] == 'S')
	{
		if (ft_texture(parse, parse->south_path, mlx) == -1)
		{
			write(0, "error in south path.\n", 21);
			return (-1);
		}
	}
	if (texture_next(parse, mlx) == -1)
		return (-1);
	return (1);
}
