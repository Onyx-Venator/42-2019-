/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:24:10 by cofoundo          #+#    #+#             */
/*   Updated: 2020/02/05 15:29:13 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
//# include "libft.h"

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
	int		i;
	int		j;
	char	buffer[1024];
	int		bin;
	int		count_format;
	int		save;
	int		count;
}					s_list;

int	printf(const char *, ...);

#endif
