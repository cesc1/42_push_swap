#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

t_dstack	*dstack_new()
{
	t_dstack	*dstack;

	dstack = (t_dstack *)malloc(sizeof (t_dstack));
	if (!dstack)
		exit_program(dstack);
	dstack->a = NULL;
	dstack->b = NULL;
	return (dstack);
}

void	dstack_clear(t_dstack *dstack)
{
	stack_clear(&(dstack->a));
	stack_clear(&(dstack->b));
	free(dstack);
}

void	dstack_operate(t_dstack *dstack, char	*code)
{
	if (ft_strncmp(code, "sa", 3) == 0)
		swap(dstack->a);
	else if (ft_strncmp(code, "sb", 3) == 0)
		swap(dstack->b);
	else if (ft_strncmp(code, "ss", 3) == 0)
		swap_swap(dstack->a, dstack->b);
	else if (ft_strncmp(code, "pa", 3) == 0)
		push(&(dstack->b), &(dstack->a));
	else if (ft_strncmp(code, "pb", 3) == 0)
		push(&(dstack->a), &(dstack->b));
	else if (ft_strncmp(code, "ra", 3) == 0)
		rotate(dstack->a);
	else if (ft_strncmp(code, "rb", 3) == 0)
		rotate(dstack->b);
	else if (ft_strncmp(code, "rr", 3) == 0)
		rotate_rotate(dstack->a, dstack->b);
	else if (ft_strncmp(code, "rra", 4) == 0)
		reverse_rotate(dstack->a);
	else if (ft_strncmp(code, "rrb", 4) == 0)
		reverse_rotate(dstack->b);
	else if (ft_strncmp(code, "rrr", 4) == 0)
		reverse_rotate_rotate(dstack->a, dstack->b);
	else
		exit_program(dstack);
	ft_printf("%s\n", code);
}

t_stack	*stack_dup(t_stack *stack)
{
	t_stack	*result;

	result = NULL;
	while (stack)
	{
		if (!stack_add(&result, stack->num))
		{
			stack_clear(&stack);
			return (NULL);
		}
		rotate(result);
		if (stack->idx == 0)
			break ;
		stack = stack->next;
	}
	return (result);
}

t_dstack	*dstack_dup(t_dstack *dstack)
{
	t_dstack	*result;

	result = dstack_new();
	if (!result)
		return (NULL);
	result->a = stack_dup(dstack->a);
	result->b = stack_dup(dstack->b);
	return (result);
}
