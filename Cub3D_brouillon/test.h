/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 08:05:42 by cofoundo          #+#    #+#             */
/*   Updated: 2021/03/31 08:16:53 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <math.h>
# include <fcntl.h>

# define ESC 53
# define A 0
# define S 1
# define D 2
# define W 13
# define Z 6
# define Q 12
# define T_ARR 126
# define L_ARR 123
# define R_ARR 124
# define B_ARR 125

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*adr;
	int				x;
}					t_img;

typedef struct		s_win
{
	void			*ptr;
	int				x;
	int				y;
}					t_win;

typedef struct		s_mlx
{
	void			*ptr;
	t_win 			win;
}					t_mlx;

void	ft_putnbr(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
