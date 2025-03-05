#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

int	stack_size(t_stack *stack)
{
	int	result;

	result = 0;
	while (stack)
	{
		result++;
		stack = stack->next;
	}
	return (result);
}

t_stack *stack_last(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ab_print(t_stack_ab ab)
{
	ft_printf("====Stack====\n");
	while (ab.a || ab.b)
	{
		if (ab.a)
		{
			ft_printf("%d", ab.a->num);
			ab.a = ab.a->next;
		}
		if (ab.b)
		{
			ft_printf("\t%d\n", ab.b->num);
			ab.b = ab.b->next;
		}
		else
			ft_printf("\t\n");
	}
	ft_printf("_\t_\n");
	ft_printf("a\tb\n");
}

void	exit_program(t_stack_ab *ab)
{
	ab_clear(ab);
	ft_putendl_fd("Error", 2);
	exit(1);
}
