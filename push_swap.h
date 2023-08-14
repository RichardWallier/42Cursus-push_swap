/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:05 by rwallier          #+#    #+#             */
/*   Updated: 2022/10/04 15:01:39 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack
{
	long long int	*content;
	int				size;
}	t_stack;

typedef struct s_data
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		num_args;
	int		*reference;
}				t_data;

void	sort_algorithm(t_data *data, int max_offset);

int		parse_stacks(t_data *data, size_t size, char *argv[]);

int		parse_string(t_data *data, size_t size, char *argv[]);

int		populate_args(t_data *data, size_t size, char *argv[]);

int		populate_string(t_data *data, char *argv[]);

int		parse_referene(t_data *data);

int		sort_reference(t_data *data);

int		has_field(t_stack stack, int min, int max);

int		get_field_front(t_stack stack, int min, int max);

int		get_field_back(t_stack stack, int min, int max);

int		find_big_number_index(t_stack stack);

int		find_small_number_index(t_stack stack);

int		choose_call(char *call, t_data *data);

int		error(char *error_message, t_data *data);

int		split_len(char **split);

int		is_int(t_data *data);

int		free_split(char **split);

int		calloc_double(t_data *data, size_t count, size_t size);

int		is_sorted(t_data *data);

//-----------------------------------------
//               OPERATIONS
//-----------------------------------------

int		swap_a(t_data *data);

int		swap_b(t_data *data);

int		swap_a_b(t_data *data);

int		push_a(t_data *data);

int		push_b(t_data *data);

int		rotate_a(t_data *data);

int		rotate_b(t_data *data);

int		rotate_a_b(t_data *data);

int		reverse_rotate_a(t_data *data);

int		reverse_rotate_b(t_data *data);

int		reverse_rotate_a_b(t_data *data);

int		sort_five_num(t_data *data);

void	sort_three_num(t_data *data);

// ---------------------------------------

#endif
