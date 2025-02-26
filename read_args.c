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

static int	validate_reps(t_stack *b)
{
	int	num;
	t_stack	*iterator;

	while (b->next)
	{
		num = b->num;
		iterator = b->next;
		while (iterator)
		{
			if (num == iterator->num)
				return (0);
			iterator = iterator->next;
		}
		b = b->next;
	}
	return (1);
}

static void	add_num_stack(t_stack_ab *ab, char *str, int stack_num)
{
	int	check;

	check = validate_str(str);
	if (check)
	{
		if (stack_num == 1)
			check = stack_add(&(ab->a), ft_atoi(str));
		else if (stack_num == 2)
			check = stack_add(&(ab->b), ft_atoi(str));
		else
			check = 0;
	}
	if (!check)
		exit_program(ab);
}


t_stack_ab	*read_args(int argc, char **argv)
{
	int	i;
	const int	MAX_INT = 2147483647;
	t_stack_ab	*ab;

	if (argc <= 1)
		exit(1);
	ab = ab_new(NULL, NULL);
	i = 1;
	while (argv[i] && i < MAX_INT)
	{
		add_num_stack(ab, argv[i], 2);
		i++;
	}
	if (i == MAX_INT || !validate_reps(ab->b))
		exit_program(ab);
	while (ab->b)
	{
		push(&(ab->b), &(ab->a));
	}
	return (ab);
}
