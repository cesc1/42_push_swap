#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_new(int num)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof (t_stack));
	if (!result)
		return (NULL);
	result->num = num;
	result->next = NULL;
	return (result);
}

int	stack_add(t_stack **stack, int num)
{
	t_stack *node;

	node = stack_new(num);
	if (!node)
		return (0);
	node->next = *stack;
	(*stack) = node;
	return (1);
}

void	stack_pop(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->num = 0;
	free(*stack);
	*stack = tmp;
}
