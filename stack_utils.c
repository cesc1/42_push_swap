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

void	stack_print(t_stack *a, t_stack *b)
{
	ft_printf("====Stack====\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("%d", a->num);
			a = a->next;
		}
		if (b)
		{
			ft_printf("\t%d\n", b->num);
			b = b->next;
		}
		else
			ft_printf("\t\n");
	}
	ft_printf("_\t_\n");
	ft_printf("a\tb\n");
}
