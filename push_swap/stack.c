/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzots <vzots@student.42yerevan.am>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:36:13 by vzots             #+#    #+#             */
/*   Updated: 2025/04/15 18:44:50 by vzots            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ft_stack_add_back(t_stack **stack, t_stack *new_stack)
{
	t_stack	*last_stack;

	if (!*stack)
		*stack = new_stack;
	else
	{
		last_stack = ft_stacklast(*stack);
		last_stack->next = new_stack;
	}
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_stacknew(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->next = NULL;
	return (new_stack);
}

void	init_and_fill_stack(t_stack **a, t_stack **b, int *indexed, int size)
{
	int			i;
	t_stack		*new;

	*a = NULL;
	*b = NULL;
	i = 0;
	while (i < size)
	{
		new = ft_stacknew(indexed[i]);
		if (!new)
			ft_perror_exit("f: stacknew malloc fail");
		ft_stack_add_back(a, new);
		i++;
	}
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
