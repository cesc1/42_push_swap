#include "push_swap.h"
#include "libft/libft.h"

static void	start_alg(t_stack_ab *ab)
{
	ab_operate(ab, "pb");
	if (ab->a)
	{
		ab_operate(ab, "pb");
		if (ab->b->num < ab->b->next->num)
			ab_operate(ab, "sb");
	}
}

static void	go_up(t_stack_ab *ab, int *top)
{
	if (ab->b->num == *top)
	{
		ab_operate(ab, "pb");
		*top = ab->b->num;
	}
	else
	{
		if (ab->a->num < stack_last(ab->b)->num)
			ab_operate(ab, "pb");
		else
			ab_operate(ab, "rrb");
	}
}

static void	go_down(t_stack_ab *ab, int *top)
{
	if (ab->b->next->num == *top)
	{
		ab_operate(ab, "pb");
		ab_operate(ab, "sb");
	}
	else
	{
		if (ab->a->num > ab->b->next->num)
		{
			ab_operate(ab, "pb");
			ab_operate(ab, "sb");
		}
		else
			ab_operate(ab, "rb");
	}
}

void	sort_cesc(t_stack_ab *ab)
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
		ab_operate(ab, "rb");
	while (ab->b)
		ab_operate(ab, "pa");
}
