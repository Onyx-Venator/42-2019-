/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:10:46 by cofoundo          #+#    #+#             */
/*   Updated: 2020/08/31 18:27:08 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_stend(t_list *parse, int i)
{
	int j

	i;
	while (parse->save[j++] != '\n')
		;
	while (i <= j)
	{
		if (parse->save[i] == '0')
			return (-1);
		i++;
	}
	return (j);
}

int		ft_exit_parse_map(t_list *parse, int tmp)
{
	int	i;
	int	stock;

	i = tmp;
	while ((stock = ft_check_stend(parse, i)) == -1)
	{

		if (parse->save[i] == 'N' || parse->save[i] == 'S'
			|| parse->save[i] == 'E' || parse->save[i] == 'W')
		{
			parse->spawn++;
			if (parse->bin && SPAWN != SPAWN)
				parse->bin |= 1 << 0;
			i++;
		}
		if (parse->save[i] == '0' || parse->save[i] == '1'
			|| parse->save[i] == '\n' || parse->save[i] == ' ')
			i++;
		else
			return (i--);
	}
	return (stock);
}

int		ft_map(t_list *parse)
{
	int	tmp;

	while (parse->save[parse->i_save--] != '\n')
		;
	tmp = parse->i_save + 1;
	while (parse->save[tmp++] != '\n')
		;
	tmp++;
	if (parse->save[tmp] == '\n')
		return (-2);
	tmp = ft_exit_parse_map(parse, tmp);
	if (!(parse->map = malloc(sizeof(char) * (tmp - parse->i_save + 1))))
		return (-1);
	parse->map[tmp - parse->i_save] = '\0';
	while (tmp != parse->i_save)
		parse->map[parse->i_map++] = parse->save[parse->i_save++];
	return (1);
}
