#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	num_first;

	if (!stack)
		return ;
	num_first = stack->num;
	while (stack->next)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = num_first;
}
