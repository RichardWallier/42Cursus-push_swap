#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack
{
	int	*content;
	int	size;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		num_args;
}			   t_data;

int	parse_stacks(t_data *data, size_t size, char *argv[]);

int	choose_operation(char *operation, t_data *data);

int	error(char *error_message);

int	swap_a(t_data *data);

int	swap_b(t_data *data);

int	swap_a_b(t_data *data);

int	push_a(t_data *data);

int	push_b(t_data *data);

int	rotate_a(t_data *data);

int	rotate_b(t_data *data);

int	rotate_a_b(t_data *data);

int	reverse_rotate_a(t_data *data);

int	reverse_rotate_b(t_data *data);

int	reverse_rotate_a_b(t_data *data);

#endif
