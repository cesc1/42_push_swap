#include "push_swap.h"
#include "libft/libft.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	stack_add(&a, 1);
	stack_add(&a, 2);
	stack_add(&a, 3);
	stack_print(a, b);
	push(&a, &b, "pa");
	stack_print(a, b);
	push(&a, &b, "pa");
	stack_print(a, b);
	push(&a, &b, "pa");
	stack_print(a, b);

	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
