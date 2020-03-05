/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:48:57 by cofoundo          #+#    #+#             */
/*   Updated: 2020/03/05 17:57:48 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#include "printf.h"

int		ft_verif(const char *s, char c, s_list *stock)
{
	if (s[stock->coord_s] == c)
		return (1);
	return (0);
}

int		ft_is_num(const char *s, s_list *stock)
{
	if (s[stock->coord_s] > '0' && s[stock->coord_s] <= '9')
		return (1);
	return (0);
}

void	count_format(const char *s, s_list *stock)
{
	stock->count_format = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_format = stock->count_format * 10 +
			s[stock->coord_s++] - '0';
	return ;
}

void	count_precision(const char *s, s_list *stock)
{
	stock->count_precision = 0;
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
	stock->count_precision = stock->count_precision * 10 +
		s[stock->coord_s++] - '0';
	return ;
}

void	count_wildcard(const char *s, s_list *stock)
{
	while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
	stock->count_format = stock->count_format * 10 +
		s[stock->coord_s++] - '0';
	return ;
}

void	ft_count(const char *s, s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT ||
		(stock->bin & TYPE_ZERO) == TYPE_ZERO)
	{
		if ((stock->bin & TYPE_LEFT) == TYPE_LEFT &&
			(stock->bin & TYPE_ZERO) == TYPE_ZERO)
			{
				if (s[stock->coord_s - 1] == '-')
				{
					stock->bin -= 1 << 9;
					count_format(s, stock);
					return ;
				}
				else
				{
					stock->bin -= 1 << 9;
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

int		ft_verif_convert(const char *s, s_list *stock)
{
	if (s[stock->coord_s] == 'c')
		return (stock->bin += 1);
	if (s[stock->coord_s] == 's')
		return (stock->bin += 1 << 1);
	if (s[stock->coord_s] == 'p')
		return (stock->bin += 1 << 2);
	if (s[stock->coord_s] == 'd')
		return (stock->bin += 1 << 3);
	if (s[stock->coord_s] == 'i')
		return (stock->bin += 1 << 4);
	if (s[stock->coord_s] == 'u')
		return (stock->bin += 1 << 5);
	if (s[stock->coord_s] == 'x')
		return (stock->bin += 1 << 6);
	if (s[stock->coord_s] == 'X')
		return (stock->bin += 1 << 7);
	return (-1);
}

void	wildcard(int x, s_list *stock, const char *s)
{
	if (s[stock->coord_s - 1] == '.')
	{
		stock->bin -= 1 << 8;
		stock->count_precision = x;
		if (x < 0)
		{
			stock->count_precision *= -1;
			stock->bin += 1 << 9;
		}
	}
	else
	{
		if (x < 0)
		{
			stock->count_format *= -1;
			stock->bin += 1 << 9;
		}
		stock->count_format = x;
	}
	return ;
}

void	ft_parse(const char *s, s_list *stock)
{
	while (ft_verif_convert(s, stock) = -1)
	{
		if (s[stock->coord_s] == '*')
		{
			stock->bin += 1 << 8;
			wildcard(va_arg(ap, int), stock, s);
		}
		if (s[stock->coord_s] == '-')
			stock->bin += 1 << 9;
		if (s[stock->coord_s] == '0')
			stock->bin += 1 << 10;
		if (s[stock->coord_s] == '.')
			stock->bin += 1 << 11;
		if (s[stock->coord_s] >= '1' && s[stock->coord_s] <= '9')
			ft_count(s, stock);
		stock->coord_s++;
	}
	return ;
}

int		ft_verif_buf(va_list ap, s_list *stock)
{
	if (stock->count_format > 1023 || stock->count_precision > 1023)
		return (1);
	return (0);
}

void	apply_type_left(s_list *stock)
{
	int x;

	x = -1;
	while (++x < stock->count_format)
		stock->buffer[x] = ' ';
	return ;
}

void	apply_type_zero(s_list *stock)
{
	while (stock->coord_buf < stock->count_format)
	{
		if ((stock->bin & TYPE_POINT) == TYPE_POINT)
			stock->buffer[stock->coord_buf++] = ' ';
		else
			stock->buffer[stock->coord_buf++] = '0';
	}
	return ;
}

void	apply_wildcard(s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT ||
		(stock->bin & TYPE_ZERO) == TYPE_ZERO)
			return;
	else
		{
			while (stock->coord_buf < stock->count_format)
				stock->buffer[stock->coord_buf++] = ' ';
			return ;
		}
}

void	ft_check_bin_format(s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == TYPE_LEFT)
		apply_type_left(stock);
	if ((stock->bin & TYPE_ZERO) == TYPE_ZERO)
		apply_type_zero(stock);
	if ((stock->bin & WILDCARD) == WILDCARD)
		apply_wildcard(stock);
	return ;
}

void	ft_check_bin_precision(s_list *stock)
{
	if ((stock->bin & TYPE_POINT) == TYPE_POINT)
}

void	convert_buf(va_list ap, const char *s, s_list *stock)
{
	ft_check_bin_format(stock);
	ft_check_bin_precision(stock);
}

void	start_convert(va_list ap, const char *s, s_list *stock)
{
	ft_parse(s, stock);
	if (!(ft_verif_buf(ap, stock)))
		convert_buf(ap, s, stock);
	else
		convert_malloc(ap, s, stock);
	return ;
}

void	ft_init(s_list *stock)
{
	stock->bin = 0;
	stock->coord_buf = 0;
	stock->count_buf = 0;
	stock->count_precision = 0;
	stock->count_format = 0;
	stock->apply_buf = 0;
	stock->size_wildcard = 0;
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	s_list	stock;

	stock.coord_s = 0;
	stock.count_print = 0;
	while (s[stock.coord_s])
	{
		ft_init(&stock);
		if (ft_verif(s, '%', &stock) != 0)
		{
			stock.coord_s++;
			start_convert(ap, s, &stock);
		}
		else
		{
			write(1, s[stock.coord_s], 1);
			stock.coord_s++;
			stock.count_print++;
		}
	}
	return (stock.count_print);
}

/*int	ft_flag(const char *s, s_list *stock)
{
	if (s[stock->i] == 'c')
		return (stock->bin += 1);
	if (s[stock->i] == 's')
		return (stock->bin += 1 << 1);
	if (s[stock->i] == 'p')
		return (stock->bin += 1 << 2);
	if (s[stock->i] == 'd')
		return (stock->bin += 1 << 3);
	if (s[stock->i] == 'i')
		return (stock->bin += 1 << 4);
	if (s[stock->i] == 'u')
		return (stock->bin += 1 << 5);
	if (s[stock->i] == 'x')
		return (stock->bin += 1 << 6);
	if (s[stock->i] == 'X')
		return (stock->bin += 1 << 7);
	return (0);
}

int		ft_is_num(const char *s, s_list *stock)
{
	if (s[stock->i] >= '0' && s[stock->i] <= '9')
		return (1);
	return (0);
}

void	ft_atoi(const char *s, s_list *stock)
{
	while (s[stock->i] && s[stock->i] >= '0' && s[stock->i] <= '9')
	{
		stock->count_format = stock->count_format * 10 + s[stock->i] - '0';
		stock->i++;
	}
	return ;
}

void ft_count_format(const char *s, s_list *stock)
{
	while (ft_is_num(s, stock))
		ft_atoi(s, stock);
	return ;
}

void	ft_wildcard(s_list *stock, const char *s)
{
	int	i;

	i = 0;
	stock->i++;
	ft_count_format(s, stock);
	while (++i <= stock->count_format)
	{
		stock->buffer[stock->j++] = ' ';
		stock->count++;
	}
	return ;
}

void	ft_point(s_list *stock, const char *s)
{
	int	i;

	i = 0;
	stock->i++;
	ft_count_format(s, stock);
	while (++i <= stock->count_format)
	{
		if (stock->buffer[stock->j] == '0')
		{
			stock->buffer[stock->j++] = ' ';
			stock->count++;
		}
		else
		{
			stock->buffer[stock->j++] = '0';
			stock->count++;
		}
	}
	return ;
}

void	ft_type_left(s_list *stock, const char *s)
{
	int	i;

	if ((stock->bin & TYPE_POINT) == 2048)
	{
		ft_point(stock, s);
		return ;
	}
	i = 0;
	stock->i++;
	ft_count_format(s, stock);
	while (++i <= stock->count_format)
	{
		stock->buffer[stock->j++] = ' ';
		stock->count++;
	}
	return ;
}

void	ft_zero(s_list *stock, const char *s)
{
	int	i;

	if ((stock->bin & TYPE_LEFT) == 512)//rajouter les flags de conversion la flemme la maintenant
	{
		ft_type_left(stock, s);
		return ;
	}
	i = 0;
	stock->i++;
	ft_count_format(s, stock);
	while (++i <= stock->count_format)
	{
		stock->buffer[stock->j++] = '0';
		stock->count++;
	}
	return ;
}

void	ft_format(s_list *stock, const char *s)
{
	if ((stock->bin & WILDCARD) == 256)
		ft_wildcard(stock, s);
	if ((stock->bin & TYPE_LEFT) == 512)
		ft_type_left(stock, s);
	if ((stock->bin & TYPE_ZERO) == 1024)
		ft_zero(stock, s);
	if ((stock->bin & TYPE_POINT) == 2048)
		ft_point(stock, s);
	return ;
}

int	ft_bin(const char *s, s_list *stock)
{
	while ((stock->bin = ft_flag(s, stock)) == 0 && s[stock->i])
	{
		if (s[stock->i] == '*')
			stock->bin += 1 << 8;
		if (s[stock->i] == '-')
			stock->bin += 1 << 9;
		if (s[stock->i] == '0' && (s[stock->i - 1] < '0'
			|| s[stock->i - 1] > '9'))
			stock->bin += 1 << 10;
		if (s[stock->i] == '.')
			stock->bin += 1 << 11;

		stock->i++;
	}
	return (stock->bin);
}

void	ft_convert_c(int ap, s_list *stock)
{
	unsigned char 	c;

	c = ap;
	while (stock->buffer[stock->j] == '0' || stock->buffer[stock->j] == ' ')
		stock->j++;
	if (stock->buffer[stock->j - 1] == '0'
		|| stock->buffer[stock->j - 1] == ' ')
		stock->j--;
	stock->buffer[stock->j] = c;
	stock->j++;
	return ;
}

void	ft_putstr(char *s, s_list *stock)
{
	int	i;

	i = -1;
	while (s[++i])
		stock->buffer[stock->j++] = s[i];
	stock->j++;
	return ;
}

void	ft_hexa(void *p, s_list *stock)
{
	int			i;
	long int	j;
	char		hexa[16];

	i = -1;
	j = 0;
	hexa = "0123456789abcdef";
	while(p[++i])
		j += p[i];
	while ((j / 16) != 0)
	{

	}
}

void	ft_checkflag(va_list ap, s_list *stock)
{
	if ((stock->bin & TYPE_C) == 1)
		ft_convert_c(va_arg(ap, int), stock);
	if ((stock->bin & TYPE_S) == 2)
		ft_putstr(va_arg(ap, char*), stock);
	if ((stock->bin & TYPE_P) == 4)
		ft_hexa(va_arg(ap, void *), stock);
	/*if ((stock->bin & TYPE_D) == 8) || (stock->bin & TYPE_I) == 16)
		stock->buffer[stock->j] = ft_putnbr(va_arg(ap, int));
	if ((stock->bin & TYPE_U) == 32)
		stock->buffer[stock->j] = ft_decimalunsigned(va_arg(ap, unsigned int));
	if ((stock->bin & TYPE_X) == 64)
		stock->buffer[stock->j] = ft_hexamin(ft_va_arg(ap, unsigned int));
	if ((stock->bin & BIG_X) == 128)
		stock->buffer[stock->j] = ft_hexamaj(ft_va_arg(ap, unsigned int));
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	s_list	stock;

	stock.i = 0;
	//a partir d ici boucle
	stock.j = 0;
	stock.count = 0;
	va_start(ap, s);
	while (s[stock.i])
	{
		stock.bin = 0;
		stock.count_format = 0;
		if (s[stock.i] == '%')
		{
			stock.save = stock.j;
			stock.bin = ft_bin(s, &stock);
			ft_format(&stock, s);
			stock.j = stock.save;
			ft_checkflag(ap, &stock);
		}
		else
		{
			stock.buffer[stock.j] = s[stock.i];
			stock.j++;
			stock.count++;
		}
		stock.i++;
	}
	write(1, stock.buffer, stock.j + 1);
	//return le nbr de carac affiche
	return (1);
}*/
