/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cofoundo <cofoundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:42:17 by cofoundo          #+#    #+#             */
/*   Updated: 2021/03/31 08:59:08 by cofoundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl/mlx.h"
#include "test.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr(int n, int fd)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0', fd);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr(-n, fd);
	}
	else
	{
		ft_putnbr(n / 10, fd);
		ft_putnbr(n % 10, fd);
	}
}

int ntm(int i, t_mlx *mlx)
{
	ft_putnbr(i, 1);
	if (i == 53)
		mlx_destroy_window(mlx->ptr, mlx->win.ptr);
	return (1);
}
int	main()
{
	/*t_mlx	mlx;
	t_win	win;
	t_img	img;
	mlx.ptr = NULL;
	mlx.win.ptr = NULL;
	mlx.win.x = 1920;//res fenetre retoucher parsing res
	mlx.win.y = 1080;//res fenetre retoucher parsing res
	img.ptr = NULL;
	img.adr = 0;
	img.x = 0;
	mlx.ptr = mlx_init();
	mlx.win.ptr = mlx_new_window(mlx.ptr, mlx.win.x, mlx.win.y, "test");
	mlx_key_hook(mlx.win.ptr, ntm, &mlx);
	mlx_loop(mlx.ptr);
	return (0);*/
	int i;
	i = ft_strlen ("Error in map\n");
	ft_putnbr(i, 1);
	return(0);
}
