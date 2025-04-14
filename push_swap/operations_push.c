/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:30:14 by vzots             #+#    #+#             */
/*   Updated: 2025/04/10 21:37:36 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_push_stack(t_stack **stack_first, t_stack **stack_second)
{
	t_stack	*tmp;

	if (!stack_first || !*stack_first)
		return ;
	tmp = *stack_first;
	*stack_first = tmp->next;
	tmp->next = *stack_second; 
	*stack_second = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	ft_push_stack(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_push_stack(a, b);
	write(1, "pb\n", 3);
}