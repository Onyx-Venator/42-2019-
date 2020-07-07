/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:24:10 by cofoundo          #+#    #+#             */
/*   Updated: 2020/06/25 15:55:14 by cofoundo         ###   ########.fr       */
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

typedef	struct		s_list
{
	int				coord_s;
	int				bin;
	int				coord_buf;
	char			buffer[1024];
	int				count_print;
	int				count_format;
	int				count_precision;
	int				conv_len;
}					t_list;

int					ft_printf(const char *s, ...);
void				dump_buffer(t_list *stock);
void				add_to_buff(t_list *stock, char c);
void				ft_apply_width(t_list *stock);
int					ft_strlen(char *s);
int					ft_verif(const char *s, char c, t_list *stock);
int					ft_verif_convert(const char *s, t_list *stock);
void				wildcard(int x, t_list *stock, char const *s);
void				count_precision(const char *s, t_list *stock);
void				count_format(const char *s, t_list *stock);
void				ft_count(const char *s, t_list *stock);
void				ft_parse(const char *s, t_list *stock, va_list ap);
void				ft_flag_zero(t_list *stock);
void				ft_convert_c(int x, t_list *stock);
void				add_s(t_list *stock, int x, char *s);
void				add_precision_s(t_list *stock, int x, char *s);
void				ft_convert_s(char *s, t_list *stock);
unsigned long		fact_unsigned(unsigned long y, unsigned long x);
void				ft_utoa_base_p(unsigned long x, t_list *stock, char *base);
void				add_ox(t_list *stock);
void				precision_neg_p(t_list *stock);
void				p_less_precision(unsigned long x, t_list *stock);
void				add_zero_p(t_list *stock);
void				p_precision_less_left(unsigned long x, t_list *stock);
void				p_with_precision(unsigned long x, t_list *stock);
void				ft_convert_p(unsigned long x, t_list *stock);
int					fact(int x, int y);
void				ft_putnbr(int x, t_list *stock);
void				precision_d(int x, t_list *stock);
void				format_d(t_list *stock);
void				d_precision(int x, t_list *stock);
void				d_less_precision(int x, t_list *stock);
void				ft_convert_d(int x, t_list *stock);
void				ft_convert_u(unsigned int x, t_list *stock);
int					fact_ui(unsigned int x, int y);
void				add_zero_x(t_list *stock);
void				ft_utoa_base_x(unsigned int x, t_list *stock, char *base);
void				x_less_precision(unsigned int x, t_list *stock, char *str);
void				x_precision_less_left(unsigned int x, t_list *stock,
	char *str);
void				x_with_precision(unsigned int x, t_list *stock, char *str);
void				ft_convert_x(unsigned int x, t_list *stock, char *str);
void				ft_apply_width_percent(t_list *stock);
void				ft_putnbr_u(unsigned int x, t_list *stock);
unsigned int		fact_u(unsigned int x, unsigned int y);
void				u_less_precision(unsigned int x, t_list *stock);
void				u_precision(unsigned int x, t_list *stock);
void				precision_u(unsigned int x, t_list *stock);

#endif
