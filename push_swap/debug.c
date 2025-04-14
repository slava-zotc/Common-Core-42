#include "stack.h"
#include <stdio.h>

void	print_split_check_null(char **split)
{
	int i = 0;

	while (split[i])
	{
		printf("split[%d] = \"%s\"\n", i, split[i]);
		i++;
	}
	
	// Проверка: есть ли финальный NULL
	if (split[i] == NULL)
		printf("split[%d] = NULL ✅ (ok)\n", i);
	else
		printf("split[%d] = not NULL ❌ (error)\n", i);
}

void	print_stack(t_stack *stack, const char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}