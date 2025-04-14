/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:31:53 by vzots             #+#    #+#             */
/*   Updated: 2025/04/10 17:32:38 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_rotate_stack(t_stack **stack)
{
	t_stack *first;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return;
	last = ft_stacklast(*stack);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rb(t_stack **b)
{
	ft_rotate_stack(b);
	write(1, "rb\n", 3);
}

void	ra(t_stack **a)
{
	ft_rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_rotate_stack(a);
	ft_rotate_stack(b);
	write(1, "rr\n", 3);
}