/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:24:10 by cofoundo          #+#    #+#             */
/*   Updated: 2020/03/03 13:55:17 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*
**flag c
**flag s
**flag p
**flag d
**flag i
**flag u
**flag x
**flag X
**flag *
**flag -
**flag 0
**flag .
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

typedef	struct		t_list
{
	int		coord_s;
	int		bin;
	int		coord_buf;
	char	buffer[1024];
	int		count_print;
	int		count_format;
	int		count_width;
}					s_list;

int	printf(const char *, ...);

#endif

/*int		i;
int		j;
char	buffer[1024];
int		bin;
int		count_format;
int		save;
int		count;*/
