/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:24:10 by cofoundo          #+#    #+#             */
/*   Updated: 2020/03/12 20:38:31 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

/*
** flag c 0
** flag s 1
** flag p 2
** flag d 3
** flag i 4
** flag u 5
** flag x 6
** flag X 7
** flag * 8
** flag - 9
** flag 0 10
** flag . 11
*/

# define TYPE_C 1
# define TYPE_S 2
# define TYPE_P 4
# define TYPE_D 8
# define TYPE_I 16
# define TYPE_U 32
# define TYPE_X 64
# define BIG_X 128
# define WILDCARD 256
# define TYPE_LEFT 512
# define TYPE_ZERO 1024
# define TYPE_POINT 2048
# define STOP 1023

typedef	struct		t_list
{
	int		coord_s;
	int		bin;
	int		coord_buf;
	char	buffer[1024];
	int		count_print;
	int		count_format;
	int		count_precision;
	int		conv_len;
}					s_list;

int		ft_printf(const char *, ...);

#endif
