/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssingevi <ssingevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:50:45 by ssingevi          #+#    #+#             */
/*   Updated: 2021/06/10 14:45:20 by ssingevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_isint(char const *s)
{
	int	i;
	int	n;
	long	res;

	i = 0;
	res = 0;
	n = 1;
	while ((s[i] >= '\t' && s[i] <= '\r') || s[i] == ' ')
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			n = n * -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		res = res * 10 + (s[i] - '0');
		i++;
	}
	if (res > 2147483647 || res < 0)
		return (0);
	return (1);
}

int ft_strisdgit(char *str)
{
	int i;

	i = 0;
	// printf("%s\n", str);
	if (str[0] == '-')
		i++;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}

	return (ft_isint(str));
}

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}


int	ft_isdouble(int *t, int end, int value)
{
	int i;

	i = 0;
	while (i < end && t[i] != value)
		i++;
	if (t[i] == value)
		return (1);
	return (0);
}
