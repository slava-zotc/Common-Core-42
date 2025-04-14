#include "stack.h"

/*
 * Вспомогательная функция. Возвращает текущий размер стека.
 */
static int	get_stack_size(t_stack *stack)
{
	int	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int is_sorted(t_stack *stack)
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

/*
 * Функция ищет позицию максимального элемента в стеке.
 * Переменная pos хранит индекс максимального элемента, начиная с 0.
 */
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

/*
 * Функция smart_pa_sorted выполняет операцию PA (перекладывание из стека B в A)
 * и сразу проверяет, нужно ли выполнять вращение стека A для поддержания его сортированности.
 */
void	smart_pa_sorted(t_stack **a, t_stack **b)
{
	pa(a, b);
	/* Если в стеке A есть хотя бы 2 элемента и они не в порядке возрастания,
	   выполняется операция RA для корректировки */
	if (*a && (*a)->next && ((*a)->value > (*a)->next->value))
		ra(a);
}

/*
 * Функция smart_push_back возвращает все элементы из стека B в стек A таким образом,
 * что каждый раз сначала поднимаем максимальный элемент стека B.
 * Для этого определяется индекс максимального элемента, затем выполняются
 * соответствующие вращения (rb или rrb) для того, чтобы максимальный элемент оказался на вершине.
 */
void	smart_push_back(t_stack **b, t_stack **a)
{
	int	size;
	int	max_pos;
	int	steps;

	while (*b)
	{
		/* Определяем размер стека B */
		size = get_stack_size(*b);
		/* Находим индекс максимального элемента в B */
		max_pos = find_max_pos(*b);
		/* Если максимальный элемент ближе к вершине */
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
		/* Умное перекладывание с проверкой сортировки */
		smart_pa_sorted(a, b);
	}
}

/*
 * Функция push_chunk_elements перекладывает элементы из стека A в стек B,
 * выбирая только те, которые принадлежат заданному «чанку» – диапазону [min, max].
 * Для оптимизации осуществляется минимальное количество вращений стека A:
 *  - Если целевой элемент ближе к вершине, выполняются операции RA.
 *  - Если он ближе к низу, используются RRA.
 * После операции PB, если значение элемента меньше медианы чанка, выполняется RB.
 */
void	push_chunk_elements(t_stack **a, t_stack **b, int min, int max)
{
	int		pos;
	int		size;
	int		median;
	t_stack	*tmp;
	int		index;

	median = (min + max) / 2;
	while (1)
	{
		/* Ищем первый элемент в A, который входит в диапазон [min, max] */
		pos = -1;
		index = 0;
		tmp = *a;
		while (tmp)
		{
			if (tmp->value >= min && tmp->value <= max)
			{
				pos = index;
				break;
			}
			index++;
			tmp = tmp->next;
		}
		if (pos == -1)
			break;  // Все элементы данного чанка обработаны

		/* Определяем размер стека A */
		size = get_stack_size(*a);
		/* Оптимальное вращение стека A */
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			int steps = size - pos;
			while (steps-- > 0)
				rra(a);
		}
		/* Выполняем операцию PB */
		pb(a, b);
		/* Если значение элемента меньше медианы чанка, делаем RB */
		if ((*b)->value < median)
			rb(b);
	}
}

/*
 * Функция sort_3 сортирует стек ровно из трёх элементов.
 *
 * Алгоритм:
 *   - Если стек уже отсортирован (a < b < c) – ничего не делаем.
 *   - Если a > b и b < c:
 *       • Если a < c, достаточно поменять первые два элемента (sa).
 *       • Если a > c, выполняем поворот вверх (ra), чтобы наибольший элемент ушёл вниз.
 *   - Если a < b и b > c:
 *       • Если a < c, сначала меняем первые два (sa), затем выполняем поворот вверх (ra).
 *       • Если a > c, делаем обратный поворот (rra).
 *   - Если a > b и b > c:
 *       • Меняем первые два элемента (sa), а затем делаем обратный поворот (rra).
 */

 void	sort_3(t_stack **stack)
{
	const int a = ((*stack)->value);
	const int b = ((*stack)->next->value);
	const int c = ((*stack)->next->next->value);

	/* Если стек уже отсортирован – выходим */
	if (a < b && b < c)
		return ;

	if (a > b && b < c)
	{
		if (a < c)
			sa(stack);
		else
			ra(stack);
	}
	else if (a < b && b > c)
	{
		if (a < c)
		{
			sa(stack);
			ra(stack);
		}
		else
			rra(stack);
	}
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	rotate_stack_to_target(t_stack **a, int size, int target)
{
	int		pos = 0;
	t_stack	*tmp;

	tmp = *a;
	/* Ищем позицию элемента, равного target */
	while (tmp && tmp->value != target)
	{
		pos++;
		tmp = tmp->next;
	}
	/* Если элемент ближе к верхней части стека, используем ra */
	if (pos <= size / 2)
	{
		int i = 0;
		while (i < pos)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		int steps = size - pos;
		int i = 0;
		while (i < steps)
		{
			rra(a);
			i++;
		}
	}
}

void small_sort(t_stack **a, t_stack **b, int size)
{

	if (!b)
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
	    rotate_stack_to_target(a, size, 0);
	    // После поворотов элемент с 0 окажется наверху – отправляем его в стек B.
	    pb(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		rotate_stack_to_target(a, size, 0);
		pb(a, b);
		rotate_stack_to_target(a, size - 1, 1);
		pb(a, b);
		sort_3(a);
		pa(a, b);
		pa(a, b);
	}
	
}
/*
 * Основная функция сортировки чанками.
 *
 * Для небольшого количества элементов (<= 100) выбирается размер чанка 20,
 * для большего – около 34.
 *
 * Алгоритм:
 *   1. Последовательно перебираем чанки, определяем диапазоны значений.
 *   2. Для каждого чанка перекладываем соответствующие элементы из A в B.
 *   3. После разбиения и перекладывания всех элементов возвращаем их в A,
 *      используя умное возвращение (smart_push_back), которое поднимает максимальные значения.
 */
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
	/* Определяем размер чанка в зависимости от общего количества элементов */
	chunk_size = (size <= 100) ? 20 : 34;
	chunk_start = 0;
	while (chunk_start < size)
	{
		chunk_end = chunk_start + chunk_size - 1;
		if (chunk_end >= size)
			chunk_end = size - 1;
		/* Перекладываем элементы текущего чанка */
		push_chunk_elements(a, b, chunk_start, chunk_end);
		chunk_start += chunk_size;
	}
	/* Возвращаем элементы из B в A в отсортированном порядке */
	smart_push_back(b, a);
}
