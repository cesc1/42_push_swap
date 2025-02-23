#include "push_swap.h"
#include <stdlib.h>

int	stack_size(t_stack *stack)
{
	int	result;

	result = 0;
	while (stack)
	{
		result++;
		stack = stack->next;
	}
	return (result);
}
