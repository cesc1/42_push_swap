#include "push_swap.h"
#include "libft/libft.h"

static void	start_alg(t_dstack *ab)
{
	dstack_operate(ab, "pb");
	if (ab->a)
	{
		dstack_operate(ab, "pb");
		if (ab->b->num < ab->b->next->num)
			dstack_operate(ab, "sb");
	}
}

static void	go_up(t_dstack *ab, int *top)
{
	if (ab->b->num == *top)
	{
		dstack_operate(ab, "pb");
		*top = ab->b->num;
	}
	else
	{
		if (ab->a->num < ab->b->prev->num)
			dstack_operate(ab, "pb");
		else
			dstack_operate(ab, "rrb");
	}
}

static void	go_down(t_dstack *ab, int *top)
{
	if (ab->b->next->num == *top)
	{
		dstack_operate(ab, "pb");
		dstack_operate(ab, "sb");
	}
	else
	{
		if (ab->a->num > ab->b->next->num)
		{
			dstack_operate(ab, "pb");
			dstack_operate(ab, "sb");
		}
		else
			dstack_operate(ab, "rb");
	}
}

void	sort_cesc(t_dstack *ab)
{
	int	top;

	start_alg(ab);
	top = ab->b->num;
	while (ab->a)
	{
		if (ab->a->num > ab->b->num)
			go_up(ab, &top);
		else
			go_down(ab, &top);
	}
	while (ab->b->num != top)
		dstack_operate(ab, "rb");
	while (ab->b)
		dstack_operate(ab, "pa");
}
