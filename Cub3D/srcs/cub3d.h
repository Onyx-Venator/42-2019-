/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:23 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/26 14:33:59 by cofoundo         ###   ########.fr       */
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
** pt de spawn 0
** map is OK 1
** an resolution has been selected 2
*/

# define SPAWN 1
# define MAP 2
# define RESOLUTION 4

/*
** utilisation lib math
** pi en dure et toutes les valeurs standards
** (1/2)^(1/2)
** 2^(1/2)
** cos et sin en dure
*/

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				x;
}					t_img;

typedef struct		s_alg
{
	int				pos_x;
	int				pos_y;
	int				f_color;
	int				c_color;
	double			cam_x;
	double			cam_y;
	char			or_spawn;
	char			**map;
	int				x_mp;
	int				y_map;
}					t_alg;

typedef struct		s_mlx
{
	void			*ptr;
}					t_mlx;

typedef struct		s_win
{
	void			*ptr;
	int				x;
	int				y;
}					t_win;

typedef struct		s_list
{
	int				r_x;
	int				r_y;
	int				bin;
	int				f_r;
	int				f_g;
	int				f_b;
	int				c_r;
	int				c_g;
	int				c_b;
	int				i_save;
	int				i_map;
	int				spawn;
	char			*save;
	char			*map;
	unsigned int	*north_path;
	unsigned int	*south_path;
	unsigned int	*west_path;
	unsigned int	*east_path;
	unsigned int	*sprite_path;
	t_alg			inf_alg;
	t_win			win;
	t_mlx			mlx;
}				t_list;

int		main(int ac, char **av);
void	ft_init_struct(t_list *parse);
void	init_inf_alg(t_list *parse);
void	init_win(t_list *parse);
int		ft_init_parse(t_list *parse);
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
int		ft_resolution(t_list *parse, int x, int y);
int		ft_color(t_list *parse, int x);
int		ft_ceiling_color(t_list *parse);
int		ft_floor_color(t_list *parse);
int		norm_map(t_list *parse);
int		norm_reso(t_list *parse);
int		norm_color(t_list *parse);
int		texture(t_list *parse, t_mlx *mlx);
int		texture_next(t_list *parse, t_mlx *mlx);
int		ft_texture(t_list *parse, unsigned int *path, t_mlx *mlx);
int		ft_print(t_list *parse);
void	ft_spawn(t_list *parse);
void	format_color(t_list *parse);
void	ft_or_cam(t_list *parse);
void	ft_img(t_list *parse);

#endif
