/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:23 by cofoundo          #+#    #+#             */
/*   Updated: 2020/10/20 12:03:14 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>

/*
** spawn 0
** map is OK 1
** an resolution has been selected 2
*/

# define SPAWN 1
# define MAP 2
# define RESOLUTION 4

typedef struct		s_img
{
	void						*ptr;
	unsigned int		*adr;
	int							x;
}									t_img;

typedef struct		s_mlx
{
	void						*ptr;
}									t_mlx;

typedef struct		s_win
{
	void						*ptr;
	int							x;
	int							y;
}									t_win;

typedef struct		s_list
{
	int							bin;
	char						*save;
	t_img 					img;
	t_mlx 					mlx;
	t_win 					win;
}									t_list;

int			main(int ac, char **av);
void		ft_init_struct(t_list *parse);
void		init_img(t_list *all);
void		init_win(t_list *all);
void		init_mlx(t_list *all);
size_t	ft_strlen(char *s);
int			fd_error(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_get_next_line(t_list *all, char *config);
int			ft_parse(t_list *all);
#endif
