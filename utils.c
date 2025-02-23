#include "push_swap.h"
#include "libft/libft.h"
#include <stdlib.h>

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
	{
		free(split[i]);
	}
	free(split);
}

void	print_title(const char *title, const char *expect)
{
	char	**split;
	int	i;

	if (!title)
		return ;
	split = ft_split(expect, ' ');
	if (!split)
	{
		ft_printf("Error: out of memory\n");
		return ;
	}
	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(title, split[i], ft_strlen(split[i] + 1)) == 0)
		{
			ft_printf("%s\n", title);
			free_split(split);
			return ;
		}
	}
	ft_printf("Error: wrong title name\n");
	free_split(split);
}
