/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <<marvin@42.fr>>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:38:37 by ashalagi          #+#    #+#             */
/*   Updated: 2023/08/03 10:55:32 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# include <ctype.h>

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_stack
{
	int					nbr;
	int					index;
	struct s_stack		*next;
	struct s_stack		*prev;	
}						t_stack;

/* errors */
void		ft_error(void);
int			is_numeric(const char *str);
int			check_parameter_is_numeric(char *av);
int			check_parameters_are_numeric(int ac, char **av);
int			ft_checkdup(t_stack *a);

/* utils */
long int	ft_atoi_long(char *str, t_stack *a);
void		ft_freestr(char **strs);
t_stack		*ft_divide_numbers(char **argv);
t_stack		*ft_check_if_quotes(int argc, char **argv);

/* stack_list */
void		ft_stack_add_back(t_stack **lst, t_stack *stack_new);
t_stack		*ft_new_stack(int content);
int			ft_stack_size(t_stack *lst);
t_stack		*ft_stack_last(t_stack *lst);

/* check_stack */
void		stack_free(t_stack **lst);
int			ft_check_if_sorted(t_stack *stack_a);
int			ft_min(t_stack *a);
int			ft_max(t_stack *a);
void		print_stack(t_stack *stack);

/* sorting_swap_push */
void		ft_sa(t_stack **a, int j);
void		ft_sb(t_stack **b, int j);
void		ft_pa(t_stack **a, t_stack **b, int j);
void		ft_pb(t_stack **stack_a, t_stack **stack_b, int j);

/* sorting_rotate_reverse */
void		ft_ra(t_stack **a, int j);
void		ft_rb(t_stack **b, int j);
void		ft_rra(t_stack **a, int j);
void		ft_rrb(t_stack **b, int j);

/* sorting_ss_rr */
void		ft_ss(t_stack **a, t_stack **b, int j);
void		ft_rr(t_stack **a, t_stack **b, int j);
void		ft_rrr_2(t_stack **b, int j);
void		ft_rrr(t_stack **a, t_stack **b, int j);

/* sorting_algo_three */
int			ft_find_index(t_stack *a, int nbr);
void		ft_sort_three(t_stack **stack_a);

/* sorting_algo */
void		ft_sort_b_till_three(t_stack **stack_a, t_stack **stack_b);
t_stack		*ft_sort_b(t_stack **stack_a);
t_stack		**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void		ft_sorting(t_stack **stack_a);

/* rotation_combinations */
int			ft_rotate_type_ba(t_stack *a, t_stack *b);
int			ft_rotate_type_ab(t_stack *a, t_stack *b);

/* rotation_case_ab */
int			ft_find_place_b(t_stack *stack_b, int nbr_push);
int			ft_case_rarb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb(t_stack *a, t_stack *b, int c);

/* otation_case_ba */
int			ft_find_place_a(t_stack *stack_a, int nbr_push);
int			ft_case_rarb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rarrb_a(t_stack *a, t_stack *b, int c);
int			ft_case_rrarb_a(t_stack *a, t_stack *b, int c);

/* make_case_rotation */
int			ft_make_rarb(t_stack **a, t_stack **b, int c, char s);
int			ft_make_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			ft_make_rrarb(t_stack **a, t_stack **b, int c, char s);
int			ft_make_rarrb(t_stack **a, t_stack **b, int c, char s);

/* checker */
void		ft_check_line_2(t_stack **a, t_stack **b, char *line);
char		*ft_check_line(t_stack **a, t_stack **b, char *line);
void		ft_check_commandes(t_stack **a, t_stack **b, char *line);

/* checker_utils */
void		ft_error_checker(void);

#endif
