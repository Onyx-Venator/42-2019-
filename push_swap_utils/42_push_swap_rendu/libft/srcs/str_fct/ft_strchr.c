/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:29:43 by tsantoni          #+#    #+#             */
/*   Updated: 2019/10/16 18:02:42 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (((char *)s)[i] != '\0')
	{
		if (((char *)s)[i] == (char)c)
			return (&((char *)s)[i]);
		else
			i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	else
		return ((void*)0);
}
