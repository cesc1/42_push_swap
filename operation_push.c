#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	if (*a)
	{
		stack_add(b, (*a)->num);
		stack_pop(a);
	}
}
