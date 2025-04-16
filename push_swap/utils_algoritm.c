/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algoritm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:07:58 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 18:38:01 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_position_in_range(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value >= min && a->value <= max)
			return (pos);
		a = a->next;
		pos++;
	}
	return (-1);
}

int	find_max_pos(t_stack *stack)
{
	int		max;
	int		pos;
	int		index;
	t_stack	*tmp;

	max = stack->value;
	pos = 0;
	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max)
		{
			max = tmp->value;
			pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (pos);
}
