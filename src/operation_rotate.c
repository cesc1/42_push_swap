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

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	t_stack	*original;
	int	tmp[2];

	if (!stack)
		return ;
	original = stack;
	tmp[0] = stack->num;
	while (stack->next)
	{
		tmp[1] = stack->next->num;
		stack->next->num = tmp[0];
		tmp[0] = tmp[1];
		stack = stack->next;
	}
	original->num = tmp[0];
}

void	reverse_rotate_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
