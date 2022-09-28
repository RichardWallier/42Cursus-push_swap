/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/28 19:25:29 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	find_big_number_index(t_stack stack)
{
	int	index;
	int	index_max;

	index = 0;
	index_max = 0;
	while (index < stack.size)
	{
		if (stack.content[index_max] < stack.content[index])
			index_max = index;
		index++;
	}
	return (index_max);
}

int	find_small_number_index(t_stack stack)
{
	int	index;
	int	index_min;

	index = 0;
	index_min = 0;
	while (index < stack.size)
	{
		if (stack.content[index_min] > stack.content[index])
			index_min = index;
		index++;
	}
	return (index_min);
}

void	print_stack(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->num_args)
	{
		ft_printf("stack_a[%i]: %i || stack_b[%i]: %i\n", index, data->stack_a.content[index],
		index, data->stack_b.content[index]);
		index++;
	}
	ft_printf("\n\n");
}

int	sort_five_num(t_data *data)
{
	int	index;
	int	smallest;

	index = 0;
	smallest = find_small_number_index(data->stack_a);
	while (index++ < smallest)
		choose_call("ra", data);
	choose_call("pb", data);
	index = 0;
	smallest = find_small_number_index(data->stack_a);
	while (index++ < smallest)
		choose_call("ra", data);
	choose_call("pb", data);
	sort_three_num(data);
	if (data->stack_b.content[0] < data->stack_b.content[1])
		choose_call("sb", data);
	choose_call("pa", data);
	choose_call("pa", data);
	return (1);
}

int	sort_three_num(t_data *data)
{
	int	nums[3];

	nums[0] = data->stack_a.content[0];
	nums[1]	= data->stack_a.content[1];
	nums[2]	= data->stack_a.content[2];
	if (nums[0] > nums[1] && nums[0] < nums[2] && nums[1] < nums[2])
		choose_call("sa", data);
	if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
	{/*3 2 1*/
		choose_call("sa", data);
		choose_call("rra", data);
	}
	if (nums[0] > nums[1] && nums[0] > nums[2] && nums[1] < nums[2])
		choose_call("ra", data);
	if (nums[0] < nums[1] && nums[0] < nums[2] && nums[1] > nums[2])
	{/*1 3 2*/
		choose_call("sa", data);
		choose_call("ra", data);
	}
	if (nums[0] < nums[1] && nums[0] > nums[2] && nums[1] > nums[2])
		choose_call("rra", data);
	return (1);
}

int	has_field(t_stack stack, int min, int max)
{
	int	index;

	index = 0;
	while (index < stack.size)
	{
		if (stack.content[index] >= min && stack.content[index] < max)
			return (1);
		index++;
	}
	return (0);
}

int	get_field_front(t_stack stack, int min, int max)
{
	int	index;

	index = 0;
	while (index < stack.size)
	{
		if (stack.content[index] >= min && stack.content[index] < max)
			return (index);
		index++;
	}
	return (0);
}

int	get_field_back(t_stack stack, int min, int max)
{
	int	index;

	index = stack.size - 1;
	while (index)
	{
		if (stack.content[index] >= min && stack.content[index] < max)
			return (index);
		index--;
	}
	return (0);
}

void	push_field(t_data *data, int min, int max)
{
	int	index;
	int min_index;

	while (has_field(data->stack_a, data->reference[min], data->reference[max]))
		if (data->stack_a.content[0] >= data->reference[min] && data->stack_a.content[0] < data->reference[max])
			choose_call("pb", data);
		else
			{
				index = 0;
				min_index = get_field_front(data->stack_a, data->reference[min], data->reference[max]);
				if (min_index < data->stack_a.size / 2)
					while (index++ < min_index)
						choose_call("ra", data);
				else
					while (index++ < (data->stack_a.size - min_index))
						choose_call("rra", data);
			}

}

void	push_back(t_data *data)
{
	int	index;
	int max_index;

	while (data->stack_b.size > 0)
	{
		index = 0;
		max_index = find_big_number_index(data->stack_b);
		if (max_index < (data->stack_b.size / 2))
			while (index++ < max_index)
				choose_call("rb", data);
		else 
			while (index++ < data->stack_b.size - max_index)
				choose_call("rrb", data);
		choose_call("pa", data);
	}
}

void	sort_hundred(t_data *data)
{
	int	index;
	int	offset;
	int max_offset;
	int max_index;

	max_offset = 4;
	offset = data->num_args / max_offset;
	index = 0;
	while (index < 3)
	{
		push_field(data, offset * index, offset * (index + 1));
		index++;
	}
	while (has_field(data->stack_a, data->reference[offset * 3], data->reference[data->num_args - 3]))
		push_field(data, offset * (max_offset - 1), data->num_args - 3);
	sort_three_num(data);
	while (data->stack_b.size > 0)
	{
		index = 0;
		max_index = find_big_number_index(data->stack_b);
		if (max_index < (data->stack_b.size / 2))
			while (index++ < max_index)
				choose_call("rb", data);
		else 
			while (index++ < data->stack_b.size - max_index)
				choose_call("rrb", data);
		choose_call("pa", data);
	}
}


void	sort_algorithm(t_data *data)
{
	int	index;
	int	offset;
	int max_offset;
	int max_index;

	max_offset = 15;
	offset = data->num_args / max_offset;
	index = 0;
	while (index < (max_offset - 1))
	{
		push_field(data, offset * index, offset * (index + 1));
		index++;
	}
	while (has_field(data->stack_a, data->reference[offset * (max_offset - 1)], data->reference[data->num_args - 3]))
		push_field(data, offset * (max_offset - 1), data->num_args - 3);
	sort_three_num(data);
	while (data->stack_b.size > 0)
	{
		index = 0;
		max_index = find_big_number_index(data->stack_b);
		if (max_index < (data->stack_b.size / 2))
			while (index++ < max_index)
				choose_call("rb", data);
		else 
			while (index++ < data->stack_b.size - max_index)
				choose_call("rrb", data);
		choose_call("pa", data);
	}
}

int	manual_sorting(t_data *data)
{
	int index;
	char *call;

	index = 0;
	while (1)
	{
		index = 0;
		ft_putendl_fd("", 1);
		while (index < data->num_args)
		{
			ft_printf("stack_a[%i]: %i || stack_b[%i]: %i\n", index, data->stack_a.content[index],
			index, data->stack_b.content[index]);
			index++;
		}
		call = get_next_line(0);
		ft_printf("\n-----------> call: %s", call);
		choose_call(call, data);
		free (call);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!parse_stacks(&data, argc - 1, argv))
		exit (ft_printf("Error\n"));
	parse_referene(&data);
	sort_reference(&data);
	if (argc - 1 == 3)
		sort_three_num(&data);
	else if (argc - 1 == 5)
		sort_five_num(&data);
	else if (argc - 1 <= 200)
		sort_hundred(&data);
	else 
		sort_algorithm(&data);
		// sort_hundred(&data);
	// manual_sorting(&data);
	ft_printf("\n\n--------FINAL STACK-------\n\n");
	print_stack(&data);
	free(data.stack_a.content);
	free(data.stack_b.content);
	return (0);
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
