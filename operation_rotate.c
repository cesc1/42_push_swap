#include "push_swap.h"

void	rotate(t_stack *stack, const char *title)
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
	print_title(title, "ra rb");
}

void	rotate_rotate(t_stack *a, t_stack *b, const char *title)
{
	rotate(a, NULL);
	rotate(b, NULL);
	print_title(title, "rr");
}

void	reverse_rotate(t_stack *stack, const char *title)
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
	print_title(title, "rra rrb");
}

void	reverse_rotate_rotate(t_stack *a, t_stack *b, const char *title)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	print_title(title, "rrr");
}
