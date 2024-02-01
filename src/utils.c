/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:49:42 by ashalagi          #+#    #+#             */
/*   Updated: 2023/08/03 11:17:06 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_long(char *str, t_stack *a)
{
	long long int	i;
	long int		signe;
	long int		result;

	i = 0;
	signe = 1;
	result = 0;
	while ((str[i] >= '\t' && str [i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * signe);
}

/*
This function free the string which is the integer values in between quotes.
free_tab_strs
*/

void	ft_freestr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

/*
This function sorts the stacks in case of they are passed
in between quotation marks. In this scenario, this function
takes the string, and splits the numbers in order to create
seperated integer number.
*/
t_stack	*ft_divide_numbers(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i])
	{
		if (!check_parameter_is_numeric(tmp[i]))
		{
			ft_freestr(tmp);
			stack_free(&a);
			exit (1);
		}
		j = ft_atoi_long(tmp[i], NULL);
		ft_stack_add_back(&a, ft_new_stack(j));
		i++;
	}
	ft_freestr(tmp);
	return (a);
}

/*
The function checks if the number of input is less than 2.
Checks if the number of input is equal to 2. If it is, it means
it is a quoted string. Call another function. ft_divide_numbers
It checks if the number of input is greater than 2.
If it is, it lists the arguements.
*/
t_stack	*ft_check_if_quotes(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc != 2)
		ft_printf("Error! Less than 2 arguments");
	a = ft_divide_numbers(argv);
	return (a);
}
