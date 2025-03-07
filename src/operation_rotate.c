#include "push_swap.h"

void	rotate(t_stack *stack)
{
	int	first_num;

	if (!stack)
		return ;
	first_num = stack->num;
	while (stack->idx)
	{
		stack->num = stack->next->num;
		stack = stack->next;
	}
	stack->num = first_num;
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	reverse_rotate(t_stack *stack)
{
	int	first_num;
	size_t	first_idx;
	
	if (!stack)
		return ;
	first_num = stack->num;
	first_idx = stack->idx;
	while (stack->prev->idx < first_idx)
	{
		stack->num = stack->prev->num;
		stack = stack->prev;
	}
	stack->num = first_num;
}

void	reverse_rotate_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
