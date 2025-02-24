#include "push_swap.h"
#include "libft/libft.h"

int	main(void)
{
	t_stack	*a;

	a = NULL;
	add_num_stack(&a, "as");
	ft_printf("%d", a->num);

	stack_clear(&a);
	return (0);
}
