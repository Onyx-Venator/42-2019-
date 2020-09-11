/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:23 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/10 15:24:41 by cofoundo         ###   ########.fr       */
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
** pt de spawn 0
** map is OK 1
** an resolution has been selected 2
*/

# define SPAWN 1
# define MAP 2
# define RESOLUTION 4

typedef struct	s_mlx
{
	void		*ptr;
}				t_mlx;

typedef struct	s_list
{
	int			bin;
	long		r_x;
	long		r_y;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	int			i_save;
	int			i_map;
	char		*save;
	char		*map;
	int			spawn;
	char		*nort_path;
	char		*south_path;
	char		*west_path;
	char		*east_path;
	char		*sprite_path;
}				t_list;

int		main(int ac, char **av);
void	ft_init_struct(t_list *parse, t_mlx *mlx);
int		ft_init_parse(t_list *parse;
int		ft_get_next_line(t_list *parse, char *config);
char	*ft_strjoin(char *s1, char *s2);
int		ft_fd_error(int fd);
size_t	ft_strlen(char *s);
int		ft_parse(t_list *parse, t_mlx *mlx);
int		ft_map(t_list *parse);
int		ft_exit_parse_map(t_list *parse, int tmp);
int		ft_check_map(t_list *parse);
int		ft_check_stend(t_list *parse, int i);
int		ft_first_line(t_list *parse, int tmp);
int		ft_prev_end(t_list *parse, int tmp);
int		ft_resolution(t_list *parse, long x, int y);
int		ft_color(t_list *parse, int x);
int		ft_ceiling_color(t_list *parse);
int		ft_floor_color(t_list *parse);
int		norm_map(t_list *parse);
int		norm_reso(t_list *parse);
int		norm_color(t_list *parse);
int		texture(t_list *parse, t_mlx *mlx);
int		texture_next(t_list *parse, t_mlx *mlx);

#endif
