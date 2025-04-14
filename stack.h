/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:57:13 by vzots             #+#    #+#             */
/*   Updated: 2025/04/14 16:32:57 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

void	radix_sort_optimized(t_stack **a, t_stack **b, int size);
void	ft_push_stack(t_stack **stack_first, t_stack **stack_second);
void	ft_revers_stack(t_stack **stack);
void	ft_rotate_stack(t_stack **stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new_stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stacknew(int value);
void	ft_swap_stack(t_stack **stack);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		count_str_argv(char **str);
void	free_split(char **arr);
long	ft_atoi_ower(const char *str);
int		isvalid_minus(char *argv, int j);
void	print_error(void);
void	print_stack(t_stack *stack, const char *name);
int		*validator(char **argv, int argc, int *count_number);
int		*normalize_input(int *arr, int size);
void	init_and_fill_stack(t_stack **a, t_stack **b, int *indexed, int size);
void	chunk_sort(t_stack **a, t_stack **b, int size);
#endif