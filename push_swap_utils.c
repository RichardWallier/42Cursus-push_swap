/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:10:31 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/14 19:29:49 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_call(char *call, t_data *data)
{
	if (ft_strnstr(call, "rra", ft_strlen(call)))
		reverse_rotate_a(data);
	else if (ft_strnstr(call, "rrb", ft_strlen(call)))
		reverse_rotate_b(data);
	else if (ft_strnstr(call, "rrr", ft_strlen(call)))
		reverse_rotate_a_b(data);
	else if (ft_strnstr(call, "sa", ft_strlen(call)))
		swap_a(data);
	else if (ft_strnstr(call, "sb", ft_strlen(call)))
		swap_b(data);
	else if (ft_strnstr(call, "ss", ft_strlen(call)))
		swap_a_b(data);
	else if (ft_strnstr(call, "pa", ft_strlen(call)))
		push_a(data);
	else if (ft_strnstr(call, "pb", ft_strlen(call)))
		push_b(data);
	else if (ft_strnstr(call, "ra", ft_strlen(call)))
		rotate_a(data);
	else if (ft_strnstr(call, "rb", ft_strlen(call)))
		rotate_b(data);
	else if (ft_strnstr(call, "rr", ft_strlen(call)))
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
