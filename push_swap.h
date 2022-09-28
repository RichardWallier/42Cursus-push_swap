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
	int *reference;
}			   t_data;

int	parse_stacks(t_data *data, size_t size, char *argv[]);

int	parse_referene(t_data *data);

int sort_reference(t_data *data);

int	choose_call(char *call, t_data *data);

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

int	sort_five_num(t_data *data);

int	sort_three_num(t_data *data);

#endif
