#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

void	dstack_print(t_dstack dstack)
{
	ft_printf("====Stack====\n");
	while (dstack.a || dstack.b)
	{
		if (dstack.a)
		{
			ft_printf("%d\t", dstack.a->num);
			if (dstack.a->idx == 0)
				dstack.a = NULL;
			else
				dstack.a = dstack.a->next;
		}
		if (dstack.b)
		{
			ft_printf("%d\n", dstack.b->num);
			if (dstack.b->idx == 0)
				dstack.b = NULL;
			else
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
