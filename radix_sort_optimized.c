#include "stack.h"

int	count_zeros(t_stack *stack, int bit)
{
	int count = 0;
	while (stack)
	{
		if (((stack->value >> bit) & 1) == 0)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	radix_sort_optimized(t_stack **a, t_stack **b, int size)
{
	int max_bit = 0;
	int i = 0;

	while ((size - 1) >> max_bit != 0)
		max_bit++;

	while (i < max_bit)
	{
		int zero_count = count_zeros(*a, i);
		int steps = 0;

		while (zero_count > 0 || steps < size)
		{
			if ((((*a)->value >> i) & 1) == 0)
			{
				pb(a, b);
				zero_count--;
			}
			else
			{
				ra(a);
			}
			steps++;
		}

		while (*b)
			pa(a, b);

		i++;
	}
}
