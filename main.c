#include "push_swap.h"
#include "libft/libft.h"

int	main(void)
{
	t_stack	*stack;

	stack = stack_new(1);
	//ft_printf("create new stack: %d\n", stack->num);
	stack_add(&stack, 2);
	//ft_printf("add a node: %d, %d\n", stack->num, stack->next->num);
	stack_add(&stack, 3);
	//ft_printf("add a node: %d, %d, %d\n", stack->num, stack->next->num, stack->next->next->num);
	stack_pop(&stack);
	//ft_printf("remove a node: %d, %d\n", stack->num, stack->next->num);
	stack_pop(&stack);
	//ft_printf("remove a node: %d, \n", stack->num);
	stack_pop(&stack);
	//ft_printf("Is there something? %p\n", stack);
	return (0);
}
