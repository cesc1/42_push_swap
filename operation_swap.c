#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
