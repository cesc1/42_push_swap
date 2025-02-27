#include "push_swap.h"
#include "libft/libft.h"

t_stack_ab	ab_new(t_stack *a, t_stack *b)
{
	t_stack_ab	result;

	result.a = a;
	result.b = b;
	return (result);
}

void	ab_clear(t_stack_ab *ab)
{
	stack_clear(&(ab->a));
	stack_clear(&(ab->b));
}

void	ab_operate(t_stack_ab *ab, char	*code)
{
	if (ft_strncmp(code, "sa", 3) == 0)
		swap(ab->a);
	else if (ft_strncmp(code, "sb", 3) == 0)
		swap(ab->b);
	else if (ft_strncmp(code, "ss", 3) == 0)
		swap_swap(ab->a, ab->b);
	else if (ft_strncmp(code, "pa", 3) == 0)
		push(&(ab->b), &(ab->a));
	else if (ft_strncmp(code, "pb", 3) == 0)
		push(&(ab->a), &(ab->b));
	else if (ft_strncmp(code, "ra", 3) == 0)
		rotate(ab->a);
	else if (ft_strncmp(code, "rb", 3) == 0)
		rotate(ab->b);
	else if (ft_strncmp(code, "rr", 3) == 0)
		rotate_rotate(ab->a, ab->b);
	else if (ft_strncmp(code, "rra", 4) == 0)
		reverse_rotate(ab->a);
	else if (ft_strncmp(code, "rrb", 4) == 0)
		reverse_rotate(ab->b);
	else if (ft_strncmp(code, "rrr", 4) == 0)
		reverse_rotate_rotate(ab->a, ab->b);
	else
		exit_program(ab);
	ft_printf("%s\n", code);
}
