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

void	add_num_stack(t_stack **stack, char *str)
{
	if (validate_str(str))
	{
		if (!stack_add(stack, ft_atoi(str)))
		{
			stack_clear(stack);
			ft_printf("Error\n");
			exit(1);
		}

	}
	else
	{
		stack_clear(stack);
		ft_printf("Error\n");
		exit(1);
	}	
}
