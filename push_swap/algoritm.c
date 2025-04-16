/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:54:07 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 18:23:23 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push_chunk_elements(t_stack **a, t_stack **b, int min, int max)
{
	int		pos;
	int		median;

	median = (min + max) / 2;
	while (1)
	{
		pos = find_position_in_range(*a, min, max);
		if (pos == -1)
			break ;
		rotate_stack_to_top(a, pos);
		pb(a, b);
		if ((*b)->value < median)
			rb(b);
	}
}

void	sort_3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	rotate_stack_to_target(t_stack **a, int target)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *a;
	while (tmp && tmp->value != target)
	{
		pos++;
		tmp = tmp->next;
	}
	rotate_stack_to_top(a, pos);
}

void	small_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		rotate_stack_to_target(a, 0);
		pb(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		rotate_stack_to_target(a, 0);
		pb(a, b);
		rotate_stack_to_target(a, 1);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		pa(a, b);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, int size)
{
	int	chunk_size;
	int	chunk_start;
	int	chunk_end;

	if (is_sorted(*a))
		return ;
	if (size < 6)
	{
		small_sort(a, b, size);
		return ;
	}
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 34;
	chunk_start = 0;
	while (chunk_start < size)
	{
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end >= size)
			chunk_end = size - 1;
		push_chunk_elements(a, b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	smart_push_back(b, a);
}
