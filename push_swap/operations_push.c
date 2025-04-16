/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:30:14 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 18:39:04 by vzots            ###   ########.fr       */
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

void	smart_pa_sorted(t_stack **a, t_stack **b)
{
	pa(a, b);
	if (*a && (*a)->next && ((*a)->value > (*a)->next->value))
		ra(a);
}

void	smart_push_back(t_stack **b, t_stack **a)
{
	int	size;
	int	max_pos;
	int	steps;

	while (*b)
	{
		size = get_stack_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			steps = size - max_pos;
			while (steps-- > 0)
				rrb(b);
		}
		smart_pa_sorted(a, b);
	}
}
