#include "push_swap.h"
#include "libft/libft.h"

static t_stack	*sort_bubble_stack(t_stack *stack)
{
	t_stack	*result;
	t_stack *start;
	size_t	i;

	result = stack_dup(stack);
	if (!result)
		return (NULL);
	start = result;
	i = 0;
	while (i < stack->idx && result)
	{
		while (result->idx > i)
		{
			if (result->num < result->next->num)
				swap(result);
			result = result->next;
		}
		result = start;
		i++;
	}
	return (result);
}

static void	resort(t_stack *stack, t_stack **result, int num)
{
	while (stack)
	{
		if (num == stack->num)
		{
			stack_add(result, stack->idx);
			rotate(*result);
			return ;
		}
		if (stack->idx == 0)
		{
			ft_printf("Error: Problem with the resorting\n");
			break;
		}
		stack = stack->next;
	}
}

t_stack	*transform(t_stack *stack)
{
	t_stack	*stack_sorted;
	t_stack	*result;

	stack_sorted = sort_bubble_stack(stack);
	if (!stack_sorted)
		return (NULL);
	result = NULL;
	while (stack)
	{
		resort(stack_sorted, &result, stack->num);
		if (stack->idx == 0)
			break;
		stack = stack->next;
	}
	stack_clear(&stack_sorted);
	return (result);
}
