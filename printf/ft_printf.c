/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:48:57 by cofoundo          #+#    #+#             */
/*   Updated: 2020/03/03 13:55:19 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_wildcard(const char *s, s_list *stock, int x)
{
	int	y;

	y = -1;
	stock->bin = WILDCARD;
	stock->coord_s++;
	stock->count_format = x;
	while (++y < x)
	{
		stock->buffer[stock->coord_buf++] = ' ';

	}
}

int		check_format(const char *s, s_list *stock, va_list ap)
{
	/*stock->count_format = 0;
	if (s[stock->coord_s] == '*')
		ft_wildcard(s, stock, va_arg(ap, int));
	if (s[stock->coord_s] == '-')
		ft_type_left(s, stock);
	if (s[stock->coord_s] == '0')
		ft_type_zero(s, stock);
	if (s[stock->coord_s] == '.')
		ft_type_point(s, stock);*/
	return (0);
}

int		ft_verif_flag(const char *s, s_list *stock)
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

int		ft_convert(const char *s, s_list *stock)
{
	return (0);
}

void	ft_count(const char *s, s_list *stock)
{
	if ((stock->bin & TYPE_LEFT) == 512 ||
		(stock->bin & TYPE_ZERO) == 1024)
	{
		stock->count_format = 0;
		while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
			stock->count_format = stock->count_format * 10 +
				s[stock->coord_s++] - '0';
	}
	else if ((stock->bin & TYPE_POINT) == 2048)
	{
		stock->count_width = 0;
		while (s[stock->coord_s] >= '0' && s[stock->coord_s] <= '9')
		stock->count_width = stock->count_width * 10 +
			s[stock->coord_s++] - '0';
	}
	else
		return ;
	stock->coord_s--;
	return;
}

void	ft_parse(const char *s, s_list *stock)
{
	while (ft_verif_convert(s, stock) = -1)
	{
		if (s[stock->coord_s] == '*')
			stock->bin += 1 << 8;
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
}

void	start_convert(va_list ap, const char *s, s_list *stock)
{
	ft_parse(s, stock);
	return ;
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	s_list	stock;

	stock.coord_s = 0;
	stock.count_print = 0;
	while (s[stock.coord_s])
	{
		stock.bin = 0;
		stock.coord_buf = 0;
		stock.count_buf = 0;
		stock.count_width = 0;
		stock.count_format = 0;
		if (ft_verif(s, '%', &stock) != 0)
		{
			stock.coord_s++;
			start_convert(ap, s, &stock);
			write(1, buffer, stock.count_buf);
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
