#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_stack_ab	*ab;

	ab = read_args(argc, argv);
	sort_cesc(ab);
	ab_clear(ab);

	return (0);
}
