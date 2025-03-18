#include "push_swap.h"

static int	count_digits(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num = num >> 1;
		count++;
	}
	return (count);
}

static int	check0_add(int num, int pivot)
{
	int	num_pivot;

	num_pivot = num >> pivot;
	return (num_pivot & 1);
}

static void	transform_dstack(t_dstack *dstack)
{
	t_stack	*stack_tmp;

	stack_tmp = transform(dstack->a);
	stack_clear(&(dstack->a));
	dstack->a = stack_tmp;
}

void	sort_radix(t_dstack *dstack)
{
	int	max_digits;
	int	digit;
	int	i;
	int	n;

	transform_dstack(dstack);
	max_digits = count_digits(dstack->a->idx + 1);
	n = dstack->a->idx + 1;
	digit = 0;
	while (++digit <= max_digits)
	{
		i = -1;
		while (++i < n)
		{
			if (check0_add(dstack->a->num, digit - 1))
				dstack_operate(dstack, "pb");
			else
				dstack_operate(dstack, "ra");
		}
		while (dstack->b)
			dstack_operate(dstack, "pa");
	}
}
