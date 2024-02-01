/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:43:43 by ashalagi          #+#    #+#             */
/*   Updated: 2023/07/31 13:12:38 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	ft_check_line_2(t_stack **a, t_stack **b, char *line)
{
	if (line[2] == 'a')
		ft_rra(a, 1);
	else if (line[2] == 'b')
		ft_rrb(b, 1);
	else if (line[2] == 'r')
		ft_rrr(a, b, 1);
}

char	*ft_check_line(t_stack **a, t_stack **b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		ft_sa(a, 1);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		ft_sb(b, 1);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		ft_pa(a, b, 1);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		ft_pb(a, b, 1);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ft_ra(a, 1);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		ft_rb(b, 1);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_check_line_2(a, b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		ft_rr(a, b, 1);
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_ss(a, b, 1);
	else
		ft_error_checker();
	return (get_next_line(0));
}

// This function checks the validity of the commands and stack.
// If it is valid, and the stack_a is sorted, the program prints "OK".
void	ft_check_commandes(t_stack **a, t_stack **b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check_line(a, b, line);
		free(tmp);
	}
	if (*b)
		ft_printf("KO\n");
	else if (!ft_check_if_sorted(*a))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free(line);
}

int	main2(t_stack *a, t_stack *b)
{
	char	*line;

	if (a == NULL)
		exit (0);
	line = get_next_line (0);
	if (!line && !ft_check_if_sorted(a))
		ft_printf ("KO\n");
	else if (!line && ft_check_if_sorted(a))
		ft_printf("OK\n");
	else
		ft_check_commandes(&a, &b, line);
	stack_free(&a);
	stack_free(&b);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_stack		*temp;
	int			i;

	b = NULL;
	a = NULL;
	if (ac == 1)
		return (0);
	if (ac == 2)
		a = ft_check_if_quotes(ac, av);
	else if (ac > 2)
	{
		if (!check_parameters_are_numeric(ac, av))
			return (1);
		i = 1;
		while (av[i])
		{
			temp = ft_new_stack(ft_atoi(av[i]));
			ft_stack_add_back (&a, temp);
			i++;
		}
	}
	return (main2(a, b));
}

/*
int main (int ac, char **av)
{
    t_stack     *a;
    t_stack     *b;
    t_stack		*temp;
    int         i;
    char        *line;

    b = NULL;
    a = NULL;

    if (ac == 1) //if no arguments
		return (0);
//        ft_printf("Error! No arguments\n");
	if (ac == 2)
		a = ft_check_if_quotes(ac, av);
	else if (ac > 2)
	{
		if (!check_parameters_are_numeric(ac, av)) //if numeric and int max
			return (1);
		i = 1;
		while (av[i])
		{
			temp = ft_new_stack(ft_atoi(av[i]));
			ft_stack_add_back (&a, temp);
			i++;
		}
	}
    if (a == NULL)
		exit (0);
	if (!ft_checkdup(a))
		return (1);
	if (ft_check_if_sorted(a))
		return (1);
	ft_sort_three(&a);
	ft_sorting(&a);
    line = get_next_line (0);
    if (!line && !ft_check_if_sorted(a))
        ft_printf ("KO3333333\n");
    else if (!line && ft_check_if_sorted(a))
		ft_printf("OK\n");
    else
        ft_check_commandes(&a, &b, line);
	stack_free(&a);
    stack_free(&b);
	return (0);
}
*/
