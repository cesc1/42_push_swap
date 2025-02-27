#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

// Structures
typedef struct s_stack
{
	int		num;
	struct	s_stack	*next;
}	t_stack;

typedef struct s_stack_ab
{
	t_stack	*a;
	t_stack	*b;
}	t_stack_ab;

// Stack
int	stack_add(t_stack **stack, int num);
void	stack_clear(t_stack **stack);
void	stack_pop(t_stack **stack);
int	stack_size(t_stack *stack);

// Stack_ab
t_stack_ab	ab_new(t_stack *a, t_stack *b);
void	ab_clear(t_stack_ab *ab);
void	ab_operate(t_stack_ab *ab, char *operation);
void	ab_print(t_stack_ab ab);
void	exit_program(t_stack_ab *ab);

// Operations
void	swap(t_stack *stack);
void	swap_swap(t_stack *a, t_stack *b);
void	push(t_stack **a, t_stack **b);
void	rotate(t_stack *stack);
void	rotate_rotate(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_rotate(t_stack *a, t_stack *b);

// Read data
void	add_num_stack(t_stack_ab *ab, char *str, int stack_num);

#endif
