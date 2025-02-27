#include "push_swap.h"
#include "libft/libft.h"

int	main(void)
{
	t_stack_ab	ab;

	ab = ab_new(NULL, NULL);
	add_num_stack(&ab, "1", 1);
	add_num_stack(&ab, "2", 1);
	add_num_stack(&ab, "3", 1);
	add_num_stack(&ab, "0", 2);
	ab_print(ab);
	ab_operate(&ab, "sa");
	ab_print(ab);
	ab_operate(&ab, "sb");
	ab_print(ab);
	ab_operate(&ab, "pb");
	ab_operate(&ab, "pb");
	ab_operate(&ab, "pb");
	ab_print(ab);
	ab_operate(&ab, "sa");
	ab_print(ab);
	ab_operate(&ab, "sb");
	ab_print(ab);
	ab_operate(&ab, "a");
	ab_clear(&ab);

	return (0);
}
