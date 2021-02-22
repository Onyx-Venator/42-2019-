/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:22:23 by cofoundo          #+#    #+#             */
/*   Updated: 2021/01/25 11:29:51 by anonymous        ###   ########.fr       */
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
*/

# define RES 1
# define NO 2
# define SO 4
# define F 8
# define C 16
# define S 32
# define WE 64
# define EA 128
# define RES_X_MAX 1920
# define RES_Y_MAX 1080

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

typedef	struct		s_utils
{
	int							res_x;
	int							res_y;
	int							floor_color;
	int							ceiling_color;
	unsigned int		*north_path;
	unsigned int		*south_path;
	unsigned int		*sprite_path;
	unsigned int		*west_path;
	unsigned int		*east_path;
	char						**map;
}									t_utils;

typedef struct		s_list
{
	int							bin;
	char						*save;
	t_img 					img;
	t_mlx 					mlx;
	t_win 					win;
	t_utils					utils;
}									t_list;

int			main(int ac, char **av);
void		ft_init_struct(t_list *parse);
void		init_img(t_list *all);
void		init_win(t_list *all);
void		init_mlx(t_list *all);
void		init_utils(t_list *all);
size_t	ft_strlen(char *s);
int			fd_error(int fd);
char		*ft_strjoin(char *s1, char *s2);
int			ft_get_next_line(t_list *all, char *config);
int			init_parse(t_list *all);
int			check_c(char *str, int i);
int			parse_res(char *str, int i, t_list *all);
void		parser_error(int i);
int			ft_atoi(char *str, int i, t_list *all);
void		check_res(t_list *all);
int			parse_no(char *str, int i , t_list *all);
int			parse_so(char *str, int i , t_list *all);
int			check_texture(char *path, unsigned int **adr, t_list *all);
int			parse_color(char *str, int i, t_list *all, int color);
int 		color(char *str, int i, int color);
int			parse_sprite(char *str, int i, t_list *all);
int			parse_we(char *str, int i, t_list *all);
int			parse_ea(char *str, int i, t_list *all);
int			parse_map(char *str, int i, t_list *all);
int			if_line(char *str, int i);
int			copy_map(char *str, int start, int end, t_list *all);
int			alloc_line(char *str, int j, int end, t_list *all);

#endif
