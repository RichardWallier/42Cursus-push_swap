/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:10:31 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/11 14:39:12 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_operation(char *operation, t_data *data)
{
	if (ft_strnstr(operation, "rra", ft_strlen(operation)))
		reverse_rotate_a(data);
	else if (ft_strnstr(operation, "rrb", ft_strlen(operation)))
		reverse_rotate_b(data);
	else if (ft_strnstr(operation, "rrr", ft_strlen(operation)))
		reverse_rotate_a_b(data);
	else if (ft_strnstr(operation, "sa", ft_strlen(operation)))
		swap_a(data);
	else if (ft_strnstr(operation, "sb", ft_strlen(operation)))
		swap_b(data);
	else if (ft_strnstr(operation, "ss", ft_strlen(operation)))
		swap_a_b(data);
	else if (ft_strnstr(operation, "pa", ft_strlen(operation)))
		push_a(data);
	else if (ft_strnstr(operation, "pb", ft_strlen(operation)))
		push_b(data);
	else if (ft_strnstr(operation, "ra", ft_strlen(operation)))
		rotate_a(data);
	else if (ft_strnstr(operation, "rb", ft_strlen(operation)))
		rotate_b(data);
	else if (ft_strnstr(operation, "rr", ft_strlen(operation)))
		rotate_a_b(data);
	return (1);
}

int	parse_stacks(t_data *data, size_t size, char *argv[])
{
	size_t index;

	data->num_args = size;
	data->stack_a.size = size;
	data->stack_b.size = 0;
	data->stack_a.content = ft_calloc(size, sizeof(int));
	data->stack_b.content = ft_calloc(size, sizeof(int));
	index = 0;
	while (index < size)
	{
		data->stack_a.content[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	return (1);
}
