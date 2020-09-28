/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 15:20:39 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/19 12:25:11 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_txt(char *path, void *tmp)
{
	free(path);
	free(tmp);
}

int		ft_texture(t_list *parse, unsigned int *path, t_mlx *mlx)
{
	char	*paths;
	int		tab[8];
	void	*tmp;

	tab[0] = 0;
	parse->i_save++;
	while (parse->save[parse->i_save] == ' ')
		parse->i_save++;
	tab[1] = parse->i_save;
	while (parse->save[parse->i_save++] != '\n')
		tab[0]++;
	if (!(paths = malloc(sizeof(char) * (tab[0] + 1))))
		return (-1);
	paths[tab[0]] = '\0';
	tab[0] = 0;
	while (tab[1] < parse->i_save)
		paths[tab[0]++] = parse->save[tab[1]++];
	if ((tab[2] = open(paths, O_RDONLY)) == -1)
		return (-1);
	close(tab[2]);
	tmp = mlx_xpm_to_image(mlx->ptr, &paths, &tab[3], &tab[4]);
	if (tmp == NULL || tab[3] != 64 || tab[4] != 64)
		return (-1);
	path = (unsigned int *)mlx_get_data_addr(tmp, &tab[5], &tab[6], &tab[7]);
	free_txt(paths, tmp);
	return (1);
}

int		texture_next(t_list *parse, t_mlx *mlx)
{
	if (parse->save[parse->i_save] == 'W')
	{
		if (ft_texture(parse, parse->west_path, mlx) == -1)
		{
			write(0, "error in west path.\n", 20);
			return (-1);
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
