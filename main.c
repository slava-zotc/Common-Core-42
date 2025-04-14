#include "stack.h"
#include "debug.h"
#include <stdio.h>




//void	radix_sort_optimized(t_stack **a, t_stack **b, int size);

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int count_number;
	int	*indexed;
	int	*arr;

	count_number = 0;
	if (argc == 1)
		exit(1);
	arr = validator(argv, argc, &count_number);
	indexed = normalize_input(arr, count_number);
	init_and_fill_stack(&a, &b, indexed, count_number);
	chunk_sort(&a, &b, count_number);
	DEBUG_PRINT(
		printf("Original array:\n");
		for (int i = 0; i < count_number; i++)
			printf("%d ", arr[i]);
		printf("\n");
	
		printf("Indexed array:\n");
		for (int i = 0; i < count_number; i++)
			printf("%d ", indexed[i]);
		printf("\n");
	
		print_stack(a, "Stack a");
		print_stack(b, "Stack b");
	)
	
	
	
	
	
	free(arr);
	free(indexed);
	return 0;
}