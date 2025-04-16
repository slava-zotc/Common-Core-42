/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:33:43 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 18:26:33 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_revers_stack(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	second = NULL;
	while (last->next)
	{
		second = last;
		last = last->next;
	}
	second->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrb(t_stack **b)
{
	ft_revers_stack(b);
	write(1, "rrb\n", 4);
}

void	rra(t_stack **a)
{
	ft_revers_stack(a);
	write(1, "rra\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	ft_revers_stack(a);
	ft_revers_stack(b);
	write(1, "rrr\n", 4);
}
