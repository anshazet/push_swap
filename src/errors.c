/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 07:40:58 by ashalagi          #+#    #+#             */
/*   Updated: 2023/08/03 11:13:21 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error message

void	ft_error(void)
{
	ft_printf("Error!\n");
	exit (1);
}

// Function to check if a string is numeric

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[0] && str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Function to check if parameters are numeric and int max

int	check_parameter_is_numeric(char *av)
{
	long int		param_value;
	t_stack			temp_stack;

	if (!is_numeric(av))
	{
		ft_putstr_fd("Error! Non numeric parameters\n", 2);
		return (0);
	}
	param_value = ft_atoi_long(av, &temp_stack);
	if (param_value > 2147483647 || param_value < -2147483648)
	{
		ft_putstr_fd("Error! Parameter exceeds int min/max\n", 2);
		return (0);
	}
	return (1);
}

// Function to check if parameters are numeric and int max 
int	check_parameters_are_numeric(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!check_parameter_is_numeric(av[i]))
			return (0);
		i++;
	}
	return (1);
}

// Function to check duplicate numbers
int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
			{
				ft_putstr_fd("Error! Duplicate parameters\n", 2);
				return (0);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}
