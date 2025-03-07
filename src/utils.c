#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	init_check(int	*check_print, t_dstack *dstack)
{
	check_print[0] = 0;
	check_print[1] = 0;
	if (dstack->a)
		check_print[0] = 1;
	if (dstack->b)
		check_print[1] = 1;
}

void	dstack_print(t_dstack dstack)
{
	int	check_print[2];

	init_check(check_print, &dstack);
	ft_printf("====Stack====\n");
	while (check_print[0] || check_print[1])
	{
		if (check_print[0])
		{
			ft_printf("%d", dstack.a->num);
			check_print[0] = dstack.a->idx > dstack.a->next->idx;
			dstack.a = dstack.a->next;
		}
		if (check_print[1])
		{
			ft_printf("\t%d\n", dstack.b->num);
			check_print[0] = dstack.b->num > dstack.b->next->num;
			dstack.b = dstack.b->next;
		}
		else
			ft_printf("\t\n");
	}
	ft_printf("_\t_\n");
	ft_printf("a\tb\n");
}

void	exit_program(t_dstack *dstack)
{
	dstack_clear(dstack);
	ft_putendl_fd("Error", 2);
	exit(1);
}
