#include "push_swap.h"
#include "libft/libft.h"

int	main(int argc, char **argv)
{
	t_dstack	*dstack;

	dstack = read_args(argc, argv);
	sort_radix(dstack);
	dstack_clear(dstack);

	return (0);
}
