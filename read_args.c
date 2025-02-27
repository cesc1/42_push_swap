#include "push_swap.h"
#include "libft/libft.h"

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

void	add_num_stack(t_stack_ab *ab, char *str, int stack_num)
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
