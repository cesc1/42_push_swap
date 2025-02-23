#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stddef.h>

typedef struct s_stack
{
	int		num;
	struct	s_stack	*next;
}	t_stack;

// Stack
int	stack_add(t_stack **stack, int num);
void	stack_clear(t_stack **stack);
void	stack_pop(t_stack **stack);
int	stack_size(t_stack *stack);
void	stack_print(t_stack *a, t_stack *b);
// Operations
void	swap(t_stack *stack, const char *title);
void	swap_swap(t_stack *a, t_stack *b, const char *title);
void	push(t_stack **a, t_stack **b, const char *title);
void	rotate(t_stack *stack, const char *title);
void	rotate_rotate(t_stack *a, t_stack *b, const char *title);
void	reverse_rotate(t_stack *stack, const char *title);
void	reverse_rotate_rotate(t_stack *a, t_stack *b, const char *title);

// Utils
void	print_title(const char *title, const char *expect);
#endif
