/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:48:57 by cofoundo          #+#    #+#             */
/*   Updated: 2020/03/12 20:38:32 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/******************************************************************************/

void 			dump_buffer(s_list *stock)
{
	write(1, stock->buffer, stock->coord_buf);
	stock->count_print += stock->coord_buf;
	stock->coord_buf = 0;
	return ;
}

void 			add_to_buff(s_list *stock, char c)
{
	stock->buffer[stock->coord_buf] = c;
	stock->coord_buf++;
	if (stock->coord_buf == STOP)
		dump_buffer(stock);
	return ;
}

void			ft_apply_width(s_list *stock)
{
	int		x;

	x = -1;
	if (stock->count_precision == -1)
		stock->count_precision = 0;
	if ((stock->count_format - stock->conv_len) < 0)
		return ;
	else
		{
			if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
			{
				while (++x < (stock->count_format - stock->conv_len))
					add_to_buff(stock, '0');
			}
			else
			{
				while (++x < (stock->count_format - stock->conv_len))
					add_to_buff(stock, ' ');
			}
		}
	return ;
}

/******************************************************************************/

int				ft_strlen(char *s)
{
	int		x;

	x = -1;
	while(s[++x] && s)
		;
	return (x);
}

int				ft_verif(const char *s, char c, s_list *stock)
{
	if (s[stock->coord_s] == c)
		return (-1);
	return (0);
}

/******************************************************************************/

int				ft_verif_convert(const char *s, s_list *stock)
{
	if (s[stock->coord_s] == 'c')
		return (stock->bin |= 1);
	if (s[stock->coord_s] == 's')
		return (stock->bin |= 1 << 1);
	if (s[stock->coord_s] == 'p')
		return (stock->bin |= 1 << 2);
	if (s[stock->coord_s] == 'd')
		return (stock->bin |= 1 << 3);
	if (s[stock->coord_s] == 'i')
		return (stock->bin |= 1 << 4);
	if (s[stock->coord_s] == 'u')
		return (stock->bin |= 1 << 5);
	if (s[stock->coord_s] == 'x')
		return (stock->bin |= 1 << 6);
	if (s[stock->coord_s] == 'X')
		return (stock->bin |= 1 << 7);
	return (-1);
}

void			wildcard(int x, s_list *stock, char const *s)
{
	if (s[stock->coord_s - 1] == '.')
	{
		stock->bin &= ~(1 << 8);
		stock->count_precision = x;
		if (x < 0)
		{
			stock->count_precision *= -1;
			stock->bin &= ~(1 << 8);
		}
	}
	else
	{
		stock->count_format = x;
		if (x < 0)
		{
			stock->count_format *= -1;
			stock->bin |= 1 << 9;
		}
	}
	return ;
}

void			count_precision(const char *s, s_list *stock)
{
	stock->count_precision = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
	stock->count_precision = stock->count_precision * 10 +
		s[stock->coord_s++] - '0';
	stock->coord_s--;
	return ;
}

void			count_format(const char *s, s_list *stock)
{
	stock->count_format = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_format = stock->count_format * 10 +
			s[stock->coord_s++] - '0';
	stock->coord_s--;
	return ;
}

void			ft_count(const char *s, s_list *stock)
{
	if (s[stock->coord_s - 1] == '-' || s[stock->coord_s - 1] == '0')
	{
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT &&
			(stock->bin & TYPE_ZERO) == TYPE_ZERO)
			{
				stock->bin &= ~(1 << 10);
				count_format(s, stock);
				return ;
			}
		count_format(s, stock);
	}
	else if (s[stock->coord_s - 1] == '.')
		count_precision(s, stock);
	else if (s[stock->coord_s - 1] == '%')
		count_format(s, stock);
	else
		return ;
}

void			ft_parse(const char *s, s_list *stock, va_list ap)
{
	while (ft_verif_convert(s, stock) == -1)
	{
		if (s[stock->coord_s] == '*')
		{
			stock->bin |= 1 << 8;
			wildcard(va_arg(ap, int), stock, s);
		}
		if (s[stock->coord_s] == '-')
			stock->bin |= 1 << 9;
		if (s[stock->coord_s] == '0')
			stock->bin |= 1 << 10;
		if (s[stock->coord_s] == '.')
			stock->bin |= 1 << 11;
		if (s[stock->coord_s] >= '1' && s[stock->coord_s] <= '9')
			ft_count(s, stock);
		if (s[stock->coord_s] == '%')
		{
			ft_apply_width(stock);
			add_to_buff(stock, '%');
			dump_buffer(stock);
			return ;
		}
		stock->coord_s++;
	}
	return ;
}

void			ft_flag_zero(s_list *stock)
{
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO &&
		(stock->bin & TYPE_POINT) == TYPE_POINT)
			stock->bin &= ~(1 << 10);
	return ;
}

/******************************************************************************/

void			ft_convert_c(int x, s_list *stock)
{
	stock->conv_len = 1;
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_to_buff(stock, x);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		add_to_buff(stock, x);
	}
	return ;
}

/******************************************************************************/

void			add_s(s_list *stock, int x, char *s)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		while (++x < stock->conv_len)
			add_to_buff(stock, s[x]);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		while (++x < stock->conv_len)
			add_to_buff(stock, s[x]);
	}
	return ;
}

void			add_precision_s(s_list *stock, int x, char *s)
{
	stock->conv_len = stock->count_precision;
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		while (++x < stock->conv_len)
			add_to_buff(stock, s[x]);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		while (++x < stock->conv_len)
			add_to_buff(stock, s[x]);
	}
	return ;
}

void			ft_convert_s(char *s, s_list *stock)
{
	int		x;

	x = -1;
	if (s == NULL)
	{
		dump_buffer(stock);
		write(1, "(null)", 6);
		return ;
	}
	stock->conv_len = ft_strlen(s);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		if (stock->conv_len >= stock->count_precision)
			add_precision_s(stock, x, s);
		else
			add_s(stock, x, s);
	}
	else
		add_s(stock, x, s);
	return ;
}

/******************************************************************************/

unsigned long	fact_unsigned(unsigned long y, unsigned long x)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = x;
	while (j > 0)
	{
		i++;
		j /= y;
	}
	return (i);
}

void			ft_utoa_base_p(unsigned long x, s_list *stock, char *base)
{
	unsigned long	len_base;
	unsigned long	j;
	unsigned long	tmp;

	len_base = ft_strlen(base);
	j = fact_unsigned(len_base, x);
	tmp = j;
	dump_buffer(stock);
	if (j == 0)
	{
		add_to_buff(stock, '0');
		return ;
	}
	while (j-- > 0)
	{
		stock->buffer[stock->coord_buf + j] = base[x % len_base];
		x /= len_base;
	}
	stock->coord_buf += tmp;
	return ;
}

void			add_ox(s_list *stock)
{
	add_to_buff(stock, '0');
	add_to_buff(stock, 'x');
	return ;
}

void 			precision_neg_p(s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
	{
		add_ox(stock);
		ft_apply_width(stock);
	}
	else
	{
		ft_apply_width(stock);
		add_ox(stock);
	}
	return ;
}

void 			p_less_precision(unsigned long x, s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) ==  TYPE_LEFT)
	{
		add_ox(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
		ft_apply_width(stock);
	}
	else
	{
		if((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			add_ox(stock);
			ft_apply_width(stock);
			ft_utoa_base_p(x, stock, "0123456789abcdef");
			return ;
		}
		ft_apply_width(stock);
		add_ox(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
	}
	return ;
}

void			add_zero_p(s_list *stock)
{
	while (stock->conv_len++ < stock->count_precision)
		add_to_buff(stock, '0');
	return ;
}

void 			p_precision_less_left(unsigned long x, s_list *stock)
{
	int		y;

	y = stock->conv_len;
	stock->conv_len = stock->count_precision;
	ft_apply_width(stock);
	add_ox(stock);
	while (y++ < stock->count_precision)
		add_to_buff(stock, '0');
	ft_utoa_base_p(x, stock, "0123456789abcdef");
}

void			p_with_precision(unsigned long x, s_list *stock)
{
	if (stock->count_precision >= stock->count_format)
	{
		add_ox(stock);
		add_zero_p(stock);
		ft_utoa_base_p(x, stock, "0123456789abcdef");
	}
	else
	{
		if ((stock->bin & TYPE_LEFT) ==  TYPE_LEFT)
		{
			add_ox(stock);
			add_zero_p(stock);
			ft_utoa_base_p(x, stock, "0123456789abcdef");
			ft_apply_width(stock);
		}
		else
			p_precision_less_left(x, stock);
	}
	return ;
}



void			ft_convert_p(unsigned long x, s_list *stock)
{
	stock->conv_len = fact_unsigned(16, x);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		if (x == 0 && stock->count_precision == -1)
		{
			precision_neg_p(stock);
			return ;
		}
		ft_flag_zero(stock);
		if (stock->conv_len < stock->count_precision)
			p_with_precision(x, stock);
		else
			p_less_precision(x, stock);
	}
	else
		p_less_precision(x, stock);
	return ;
}

/******************************************************************************/

int				fact(int x, int y)
{
	int		i;
	int		j;

	j = x;
	i = 0;
	if (j == 0)
		return (1);
	if (j < 0)
		i++;
	while (j != 0)
	{
		i++;
		j /= y;
	}
	return (i);
}

void			ft_convert_d(int x, s_list *stock)
{
	stock->conv_len = fact(x, 10);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
		d_precision(x, stock);
	else
		d_less_precision(x, stock);
	return ;
}

/******************************************************************************/
void			ft_flag(va_list ap, const char *s, s_list *stock)
{
	(void)s;
	if ((stock->bin & TYPE_C) == TYPE_C)
		ft_convert_c(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_S) == TYPE_S)
		ft_convert_s(va_arg(ap, char*), stock);
	if ((stock->bin & TYPE_P) == TYPE_P)
		ft_convert_p((unsigned long)va_arg(ap, unsigned long*), stock);
	if ((stock->bin & TYPE_D) == TYPE_D)
		ft_convert_d(va_arg(ap, int), stock);
	/*if ((stock->bin & TYPE_I) == TYPE_I)
		ft_convert_i();
	if ((stock->bin & TYPE_U) == TYPE_U)
		ft_convert_u();
	if ((stock->bin & TYPE_X) == TYPE_X)
		ft_convert_x();
	if ((stock->bin & BIG_X) == BIG_X)
		ft_big_x();*/
	return ;
}

void			convert(va_list ap, const char *s, s_list *stock)
{
	ft_flag_zero(stock);
	ft_flag(ap, s, stock);
	return ;
}

void			start_convert(va_list ap, const char *s, s_list *stock)
{
	ft_parse(s, stock, ap);
	convert(ap, s, stock);
	return ;
}

/******************************************************************************/

void			ft_init(s_list *stock)
{
	stock->bin = 0;
	stock->count_precision = -1;
	stock->count_format = 0;
	stock->conv_len = 0;
}

/******************************************************************************/

int				ft_printf(const char *s, ...)
{
	va_list	ap;
	s_list	stock;

	stock.coord_s = 0;
	stock.count_print = 0;
	stock.coord_buf = 0;
	va_start(ap, s);
	while (s[stock.coord_s])
	{
		ft_init(&stock);
		if (ft_verif(s, '%', &stock) != 0)
		{
			stock.coord_s++;
			start_convert(ap, s, &stock);
		}
		else
			add_to_buff(&stock, s[stock.coord_s]);
		stock.coord_s++;
	}
	dump_buffer(&stock);
	return (stock.count_print);
}

int main()
{
	printf("%d\n", ft_printf("%s",  "abc"));
}

/*int				ft_strlen(char *s)
{
	int		x;

	x = -1;
	while (s[++i])
		;
	return (i);
}

int				ft_verif(const char *s, char c, s_list *stock)
{
	if (s[stock->coord_s] == c)
		return (1);
	return (0);
}

int				ft_is_num(const char *s, s_list *stock)
{
	if (s[stock->coord_s] > '0' && s[stock->coord_s] <= '9')
		return (1);
	return (0);
}

void			count_format(const char *s, s_list *stock)
{
	stock->count_format = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_format = stock->count_format * 10 +
			s[stock->coord_s++] - '0';
	return ;
}

void			count_precision(const char *s, s_list *stock)
{
	stock->count_precision = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
	stock->count_precision = stock->count_precision * 10 +
		s[stock->coord_s++] - '0';
	return ;
}

void			count_wildcard(const char *s, s_list *stock)
{
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
	stock->count_format = stock->count_format * 10 +
		s[stock->coord_s++] - '0';
	return ;
}

void			ft_count(const char *s, s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT ||
		(stock->bin & TYPE_ZERO) == TYPE_ZERO)
	{
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT &&
			(stock->bin & TYPE_ZERO) == TYPE_ZERO)
			{
				if (s[stock->coord_s - 1] == '-')
				{
					stock->bin &= ~(1 << 11);
					count_format(s, stock);
					return ;
				}
				else
				{
					stock->bin &= ~(1 << 11);
					return ;
				}
			}
		count_format(s, stock);
	}
	else if ((stock->bin & TYPE_POINT) == 2048)
		count_precision(s, stock);
	else if (s[stock->coord_s - 1] == '%')
		count_wildcard(s, stock);
	else
		return ;
	stock->coord_s--;
	return;
}

int				ft_verif_convert(const char *s, s_list *stock)
{
	if (s[stock->coord_s] == 'c')
		return (stock->bin &= 1);
	if (s[stock->coord_s] == 's')
		return (stock->bin &= 1 << 2);
	if (s[stock->coord_s] == 'p')
		return (stock->bin &= 1 << 3);
	if (s[stock->coord_s] == 'd')
		return (stock->bin &= 1 << 4);
	if (s[stock->coord_s] == 'i')
		return (stock->bin &= 1 << 5);
	if (s[stock->coord_s] == 'u')
		return (stock->bin &= 1 << 6);
	if (s[stock->coord_s] == 'x')
		return (stock->bin &= 1 << 7);
	if (s[stock->coord_s] == 'X')
		return (stock->bin &= 1 << 8);
	return (-1);
}

void			wildcard(int x, s_list *stock, const char *s)
{
	if (s[stock->coord_s - 1] == '.')
	{
		stock->bin &= ~(1 << 9);
		stock->count_precision = x;
		if (x < 0)
		{
			stock->count_precision *= -1;
			stock->bin &= ~(1 << 9);
		}
	}
	else
	{
		if (x < 0)
		{
			stock->count_format *= -1;
			stock->bin &= 1 << 10;
		}
		stock->count_format = x;
	}
	return ;
}

void			ft_parse(const char *s, s_list *stock)
{
	while (ft_verif_convert(s, stock) = -1)
	{
		if (s[stock->coord_s] == '*')
		{
			stock->bin &= 1 << 9;
			wildcard(va_arg(ap, int), stock, s);
		}
		if (s[stock->coord_s] == '-')
			stock->bin &= 1 << 10;
		if (s[stock->coord_s] == '0')
			stock->bin &= 1 << 11;
		if (s[stock->coord_s] == '.')
			stock->bin &= 1 << 12;
		if (s[stock->coord_s] >= '1' && s[stock->coord_s] <= '9')
			ft_count(s, stock);
		stock->coord_s++;
	}
	return ;
}

int				ft_verif_precision(s_list *stock)
{
	if ((stock->bin & TYPE_POINT) == TYPE_POINT & stock->count_precision < 0)
		return (1);
	return (0);
}

void			ft_apply_width(s_list *stock)
{
	int		x;

	x = -1;
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO &&
		(stock->bin & TYPE_POINT) == TYPE_POINT)
			stock->bin &= ~(1 << 11);
	if (stock->count_format > 0)
	{
		if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		{
			while (++x < stock->count_format)
				stock->buffer[stock->coord_buf++] = ' ';
			stock->buffer[stock->coord_buf] = '\0';
		}
		while (++x < stock->count_format)
			stock->buffer[stock->coord_buf++] = ' ';
		stock->buffer[stock->coord_buf] = '\0';
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
			stock->coord_buf = 0;
		else
			stock->coord_buf--;
		return ;
	}
	return ;
}

void			ft_convert_c(int c, s_list *stock)
{
	if (ft_verif_precision(stock) && c == 0)
		return ;
	ft_apply_width(stock);
	stock->buffer[stock->coord_buf++] = c;
	stock->buufer[stock->coord_buf] = '\0';
}

void			cpy_precision(char *s, s_list *stock, int x, int y)
{
	if (y < stock->count_format)
	{
		stock->buffer[stock->coord_buf--] = '\0';
		while (s[++x] && x < stock->count_precision)
		{
			stock->buffer[stock->coord_buf - 1] =
				stock->buffer[stock->coord_buf];
			stock->buffer[stock->coord_buf--] = s[x];
		}
		return ;
	}
	stock->buffer[stock->coord_buf--] = '\0';
	while (++x < stock->count_precision)
		stock->buf[stock->coord_buf + x -
		stock->count_precision] = s[x];
	return ;
}

void			cpy(char *s, s_list *stock, int x, int y)
{
	if (y < stock->count_format)
	{
		stock->buffer[stock->coord_buf--] = '\0';
		while (s[++x])
		{
			stock->buffer[stock->coord_buf - 1] =
				stock->buffer[stock->coord_buf];
			stock->buffer[stock->coord_buf--] = s[x];
		}
		return ;
	}
	while (s1[++x])
		stock->buffer[stock->coord_buf++] = s1[x];
	stock->buffer[stock->coord_buf] = '\0';
}

void			ft_convert_s(char *s1, s_list *stock)
{
	int		x;
	int		y;

	x = -1;
	y = ft_strlen(s)
	ft_apply_width(stock);
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
	{
		if (ft_verif_precision(stock) && !s)
			return;
		cpy_precision(s, stock, x, y);
		return ;
	}
	else
	{
		cpy(s, stock, x, y);
		return ;
	}
}

unsigned long	fact(unsigned long x, unsigned long len_base)
{
	unsigned long	y;
	unsigned long	j;

	j = 0;
	y = x;
	while (y)
	{
		j++;
		y /= len_base;
	}
	return (j);
}

void			ft_utoa_base_p(unsigned long x, s_list *stock, char *base)
{
	unsigned long	len_base;
	unsigned long	j;

	len_base = ft_strlen(base);
	j = fact(len_base, x);
	ft_apply_precision(stock, j);
	stock->buffer[stock->coord_buf + j] = '\0';
	if (j >= stock->count_format)
	{
		while (stock->coord_buf <= (--j + stock->coord_buf))
		{
			stock->buffer[stock->coord_buf + j] = base[x % len_base];
			x /= len_base;
		}
	}
	else
	{
		while (stock->coord_buf <= (--j + stock->coord_buf))
		{
			stock->buffer[stock->coord_buf + j - stock->count_format]
				= base[x % len_base];
			x /= len_base;
		}
	}
	return;
}

void			ft_convert_p(unsigned long x, s_list *stock)
{
	if (stock->coord_buf == 0)
	{
		stock->buffer[stock->coord_buf++] = '0';
		stock->buffer[stock->coord_buf++] = 'x';
	}
	if (x == 0 && ft_verif_precision(stock))
		return ;
	ft_apply_width(stock);
	ft_utoa_base_p(x, stock, "0123456789abcdef");
	return ;
}

void	ft_itoa(int x, s_list *stock)
{
	int		i;
	int		diff;
}

void			ft_convert_d(int x, s_list *stock)
{
	if (ft_verif_precision(stock) && x == 0)
		return ;
	if ((stock->bin & TYPE_POINT) == TYPE_POINT && stock->count_precision == 0)
		stock->count_precision = 1;
	ft_apply_width(stock);
	ft_itoa(x, stock);
	ft_apply_precision(stock);
}

void			ft_flag(va_list ap, s_list *stock, const char *s)
{
	if ((stock->bin & TYPE_C) == TYPE_C)
		ft_convert_c(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_S) == TYPE_S)
		ft_convert_s(va_arg(ap, char*), stock, s);
	if ((stock->bin & TYPE_P) == TYPE_P)
		ft_convert_p(va_arg((unsigned long)(ap, unsigned long*)), stock);
	if ((stock->bin & TYPE_D) == TYPE_D)
		ft_convert_d(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_I) == TYPE_I)
		ft_convert_i();
	if ((stock->bin & TYPE_U) == TYPE_U)
		ft_convert_u();
	if ((stock->bin & TYPE_X) == TYPE_X)
		ft_convert_x();
	if ((stock->bin & BIG_X) == BIG_X)
		ft_big_x();
	return;
}

void			ft_write(s_list *stock)
{
	int x;

	x = -1;
	while (stock->buffer[++x])
		write(1, stock->buffer, x);
	return ;
}

void			convert_buf(va_list ap, const char *s, s_list *stock)
{
	ft_flag(ap, stock, s);
	ft_write(stock);
}*/

/*void 			add_to_buff_string(s_list *stock, const char *s)
{
	int 	i;

	i = -1;
	while (++i < stock->write_len)
	{
		stock->buffer[stock->coord_buf] = s[i];
		stock->coord_buf++;
		if (stock->coord_buf == STOP)
			dump_buffer(stock);
	}
	return ;
}*/
