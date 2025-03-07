#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	validate_str(char *str)
{
	int	i;
	int	n;
	char	*str_nosign;

	str_nosign = str;
	if (*str == '-')
		str_nosign++;
	i = -1;
	while (str_nosign[++i])
	{
		if (!ft_isdigit(str_nosign[i]))
			return (0);
	}
	n = ft_strlen(str_nosign);
	if (n < 1 || n > 10)
		return (0);
	if (n == 10)
	{
		if ((*str == '-' && ft_strncmp(str_nosign, "2147483648", n) > 0) || \
			(*str != '-' && ft_strncmp(str_nosign, "2147483647", n) > 0))
			return (0);
	}
	return (1);
}

static int	validate_rep(t_stack *b, int num)
{
	while (b)
	{
		if (num == b->num)
			return (0);
		if (b->idx <= b->next->idx)
			break;
		b = b->next;
	}
	return (1);
}

static void	add_num_stack(t_dstack *dstack, char *str, int stack_num)
{
	int	check;
	int	num;

	check = validate_str(str);
	if (check)
	{
		num = ft_atoi(str);
		if (stack_num == 1)
		{
			check = validate_rep(dstack->a, num);
			check = check && stack_add(&(dstack->a), num);
		}
		else if (stack_num == 2)
		{
			check = validate_rep(dstack->b, num);
			check = check && stack_add(&(dstack->b), num);
		}
		else
			check = 0;
	}
	if (!check)
		exit_program(dstack);
}

t_dstack	*read_args(int argc, char **argv)
{
	int	i;
	const int	MAX_INT = 2147483647;
	t_dstack	*dstack;

	if (argc <= 1)
		exit(1);
	dstack = dstack_new();
	i = 1;
	while (argv[i] && i < MAX_INT)
	{
		add_num_stack(dstack, argv[i], 2);
		i++;
	}
	if (i == MAX_INT)
		exit_program(dstack);
	while (dstack->b)
	{
		push(&(dstack->b), &(dstack->a));
	}
	return (dstack);
}
