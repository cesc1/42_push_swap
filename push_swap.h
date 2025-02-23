#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int		num;
	struct	s_stack	*next;
}	t_stack;

//list functions
int	stack_add(t_stack **stack, int num);
void	stack_clear(t_stack **stack);
void	stack_pop(t_stack **stack);
int	stack_size(t_stack *stack);

//operations
void	swap(t_stack *stack);
void	swap_swap(t_stack *a, t_stack *b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack *stack);
void	rotate_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_rotate(t_stack *a, t_stack *b);

#endif
