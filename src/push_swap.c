/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:37:55 by ashalagi          #+#    #+#             */
/*   Updated: 2023/08/03 10:49:16 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	main2(t_stack *a)
{
	if (a == NULL || !ft_checkdup(a) || ft_check_if_sorted(a))
	{
		stack_free(&a);
		exit (0);
	}
	ft_sort_three(&a);
	ft_sorting(&a);
	stack_free(&a);
	return (0);
}

int	main(int ac, char **av)
{
	int			i;
	t_stack		*a;
	t_stack		*temp;

	a = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		a = ft_check_if_quotes(ac, av);
	else if (ac > 2)
	{
		if (!check_parameters_are_numeric(ac, av))
			exit (1);
		i = 1;
		while (av[i])
		{
			temp = ft_new_stack(ft_atoi(av[i]));
			ft_stack_add_back (&a, temp);
			i++;
		}
	}
	return (main2(a));
}

/*
		after
		ft_sorting(&a);

        ft_printf("Sorted Stack: ");
        print_stack(a);

		stack_free(&a);
*/