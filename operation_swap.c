#include "push_swap.h"

void	swap(t_stack *stack, const char *title)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	print_title(title, "sa sb");
}

void	swap_swap(t_stack *a, t_stack *b, const char *title)
{
	swap(a, NULL);
	swap(b, NULL);
	print_title(title, "ss");
}
