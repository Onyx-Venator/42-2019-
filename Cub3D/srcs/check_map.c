/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 17:30:37 by cofoundo          #+#    #+#             */
/*   Updated: 2020/09/01 15:13:51 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_prev_end(t_list *parse, int tmp)
{
	int	i;

	i = 0;
	while (parse->map[parse->i_map--] != '\n')
		i++;
	while (parse->map[tmp] != '\n')
	{
		if (parse->map[tmp] == '0' && parse->map[tmp + i] != '1')
			return (-1);
		tmp++;
	}
	return (tmp);
}

int	ft_first_line(t_list *parse, int tmp)
{
	while (parse->map[tmp] != '1')
	{
		if (parse->map[tmp] == '0')
			return (-1);
		tmp++;
	}
	while (parse->map[tmp] != '\n')
	{
		if (parse->map[tmp] == '0')
		{
			if (parse->map[tmp - parse->i_map] != '1')
				return (-1);
		}
		tmp++;
	}
	tmp--;
	while (parse->map[tmp] != '1')
	{
		if (parse->map[tmp] == '0')
			return (-1);
	}
	while (parse->map[tmp++] != '\n')
		;
	return (++tmp);
}

int	ft_check_line(t_list *parse, int tmp)
{
	while (parse->map[tmp] == ' ')
	{
		tmp++;
		if (parse->map[tmp] == '0')
			return (-1);
	}
	while (parse->map[tmp] != '\n')
	{
		if (parse->map[tmp] == '0')
		{
			if (parse->map[tmp - parse->i_map] == ' '
				|| parse->map[tmp - 1] == ' ' || parseparse->map[tmp + 1])
				return (-1);
		}
		tmp++;
	}
	return (tmp);
}

int	check_map(t_list *parse)
{
	int	tmp;
	int	count;

	if (parse->spawn != 1)
		return (-1);
	if ((parse->i_map = ft_check_stend(parse, 0)) == -1)
		return (-1);
	tmp = parse->i_map + 1;
	if ((tmp = ft_first_line(parse, tmp)) == -1)
		return (-1);
	while (parse->map[tmp])
	{
		parse->i_map = tmp - 1;
		if ((tmp = ft_check_line(parse, tmp)) == -1)
			return (-1);
	}
	count = 0;
	while (count < 2)
	{
		if (parse->map[tmp] == '\n')
			count++;
		tmp--;
	}
	if ((tmp = ft_prev_end(parse, tmp)) == -1)
		return (-1);
	if (ft_check_stend(parse, tmp) == -1)
		return (-1);
	return (1);
}
