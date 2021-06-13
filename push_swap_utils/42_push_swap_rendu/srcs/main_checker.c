/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 16:42:45 by tsantoni          #+#    #+#             */
/*   Updated: 2021/05/05 18:15:09 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**ARG=`./genstack.pl 4 -2147483648 2147483647` ; echo $ARG ; ./push_swap $ARG |
** ./checker -v -c $ARG
*/

static int	exec_push_swap_instructions(char **line, t_stack **a, t_stack **b,
	t_opt opt)
{
	if (*line || ft_strlen(*line))
	{
		if (!is_instruction(*line))
			return (ERROR);
		exec_one_ope(*line, *a, *b);
		if (opt.v && ft_strlen(*line))
		{
			ft_printf("\n.........................................");
			ft_printf("\n............. executing %3s .............", *line);
			ft_printf("\n.........................................\n\n");
			if (opt.c)
				print_stacks_color(*a, *b, clst_max_size(*a, *b), *line);
			else
				print_stacks_no_color(*a, *b, clst_max_size(*a, *b));
		}
	}
	if (line)
		ft_strdel(line);
	return (SUCCESS);
}

void		checker(char **line, t_stack **a, t_stack **b, t_opt opt)
{
	char	ope[4];

	ft_bzero(ope, 4);
	while (get_next_line(0, line) > 0)
	{
		ft_strncpy(ope, *line, 3);
		if ((exec_push_swap_instructions(line, a, b, opt) == ERROR) &&
			ft_printf("Error (instruction checker)\n"))
			return ;
	}
	if (opt.c && !opt.v && ope[0])
	{
		print_legend();
		ft_printf("\n.........................................");
		ft_printf("\n............. executing %3s .............", ope);
		ft_printf("\n.........................................\n\n");
		print_stacks_color(*a, *b, clst_max_size(*a, *b), ope);
	}
	if (opt.c && opt.v && ope[0])
		print_legend();
	if (are_sorted(opt.size, *a, *b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

/*
** ./checker ou ./checker -c et/ou -v uniquement deja verifies (main_checker)
** ft_split si les args numeriques sont recus comme une seule chaine
** (inc. s'il n'y en a qu'un)
** cree un tableau d'input a partir du 1er numerique sinon (skip -c et/ou -v)
*/

static char	**check_options(int ac, char **av, t_opt *opt)
{
	char	**input;
	int		opts;

	input = NULL;
	if ((av[1] && !ft_strcmp(av[1], "-c")) ||
		(av[2] && !ft_strcmp(av[2], "-c")))
		opt->c = 1;
	if ((av[1] && !ft_strcmp(av[1], "-v")) ||
		(av[2] && !ft_strcmp(av[2], "-v")))
		opt->v = 1;
	opts = opt->c + opt->v;
	if (ac - opts == 2)
	{
		input = ft_split(av[opts + 1], ' ');
		opt->size = ft_tablen(input);
	}
	else
	{
		opt->size -= opts;
		input = ft_tabdup(&av[opts + 1]);
	}
	return (input);
}

int			main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	**input;
	t_opt	opt;

	opt.c = 0;
	opt.v = 0;
	opt.size = ac - 1;
	line = NULL;
	if (ac < 2 ||
		(ac == 2 && (!ft_strcmp(av[1], "-c") || !ft_strcmp(av[1], "-v"))) ||
		(ac == 3 && ((!ft_strcmp(av[1], "-c") || !ft_strcmp(av[1], "-v")) &&
		(!ft_strcmp(av[2], "-c") || !ft_strcmp(av[2], "-v")))))
		return (ERROR);
	input = check_options(ac, av, &opt);
	if ((check_input(opt.size, input) == ERROR) && ft_free_tab(&input))
		return (ft_printf("Error (input checker)\n"));
	a = fill_stack(opt.size, input);
	b = clst_create_root();
	checker(&line, &a, &b, opt);
	free_all(&line, &a, &b, &input);
	return (SUCCESS);
}
