#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		num;
	struct	s_stack	*next;
}	t_stack;

//list functions
t_stack	*stack_new(int num);
void	stack_push(t_stack **stack, int num);
int	stack_size(t_stack *stack);
void	stack_pop(t_stack **stack);

#endif
