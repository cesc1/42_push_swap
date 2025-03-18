#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

// Structures
typedef struct s_stack
{
	int		num;
	struct	s_stack	*next;
	struct	s_stack *prev;
	size_t	idx;
}	t_stack;

typedef struct s_dstack
{
	t_stack	*a;
	t_stack	*b;
}	t_dstack;

// Stack
int	stack_add(t_stack **stack, int num);
void	stack_clear(t_stack **stack);
void	stack_pop(t_stack **stack);
t_stack	*stack_dup(t_stack *stack);

// Stack_ab
t_dstack	*dstack_new();
void	dstack_clear(t_dstack *dstack);
void	dstack_operate(t_dstack *dstack, char *operation);
void	dstack_print(t_dstack dstack);
void	exit_program(t_dstack *dstack);
t_dstack	*dstack_dup(t_dstack *dstack);

// Operations
void	swap(t_stack *stack);
void	swap_swap(t_stack *a, t_stack *b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack *stack);
void	rotate_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_rotate(t_stack *a, t_stack *b);

// Read data
t_dstack	*read_args(int argc, char **argv);

// Transform
t_stack *transform(t_stack *stack);

// Algorithm
void	sort_cesc(t_dstack *dstack);
void	sort_radix(t_dstack *dstack);
#endif
