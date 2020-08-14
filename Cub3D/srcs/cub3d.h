/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:23 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/14 15:44:31 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <maths.h>
# include <fcntl.h>

/*
** map is OK 0
** an resolution has been selected
*/

# define MAP 1
# define RESOLUTION 2

typedef struct	s_list
{
	int			bin;
	int			r_x;
	int			r_y;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_liste;

int		main(int ac, char **av);
int		ft_init_parse(t_list *parse);

#endif
