#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_data
{
	int	*stack_a;
	int	*stack_b;
	int	stack_size_total;
	int	stack_size_a;
	int	stack_size_b;
}			   t_data;

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
