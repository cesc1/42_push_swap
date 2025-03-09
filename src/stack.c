#include "push_swap.h"
#include <stdlib.h>

static t_stack	*stack_new(int num)
{
	t_stack	*result;

	result = (t_stack *)malloc(sizeof (t_stack));
	if (!result)
		return (NULL);
	result->num = num;
	result->next = result;
	result->prev = result;
	result->idx = 0;
	return (result);
}

int	stack_add(t_stack **stack, int num)
{
	t_stack *node;

	node = stack_new(num);
	if (!node)
		return (0);
	if (*stack)
	{
		node->next = *stack;
		node->prev = node->next->prev;
		node->idx = node->next->idx + 1;
		node->next->prev = node;
		node->prev->next = node;
	}
	*stack = node;
	return (1);
}

void	stack_pop(t_stack **stack)
{
	t_stack	*tmp;

	if (!*stack)
		return ;
	if ((*stack)->idx == 0)
	{
		tmp = NULL;
	}
	else
	{
		tmp = (*stack)->next;
		tmp->prev = (*stack)->prev;
	}
	(*stack)->num = 0;
	(*stack)->idx = 0;
	free(*stack);
	*stack = tmp;
}

void	stack_clear(t_stack **stack)
{
	while (*stack)
		stack_pop(stack);
}
