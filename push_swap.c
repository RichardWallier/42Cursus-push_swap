/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/27 17:30:03 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	sort_algorithm(t_data *data)
{
	int	index;
	int	offset;
	int min_index;

	index = 0;
	offset = data->num_args / 4;
	while (index < data->num_args)
	{
		ft_printf("a[0]: %i >= ref[%i] <= ref[%i]\n", data->stack_a.content[0], data->reference[0], data->stack_a.content[offset]);
		print_stack(data);
		if (data->stack_a.content[0] >= data->reference[0] && data->stack_a.content[0] <= data->reference[offset])
			push_b(data);
		else
			rotate_a(data);
		index++;
		ft_printf("a[0]: %i >= ref[%i] <= ref[%i]\n", data->stack_a.content[0], data->reference[0], data->stack_a.content[offset]);
	}
	index = 0;
	while (index < data->num_args)
	{
	print_stack(data);
		ft_printf("a[0]: %i >= ref[%i] <= ref[%i]\n", data->stack_a.content[0], data->reference[offset], data->stack_a.content[offset * 2]);
		if (data->stack_a.content[0] >= data->reference[offset] && data->stack_a.content[0] <= data->reference[offset * 2])
			push_b(data);
		else
			rotate_a(data);
		index++;
	}
	index = 0;
	while (index < data->num_args)
	{
	print_stack(data);
		ft_printf("a[0]: %i >= ref[%i] <= ref[%i]\n", data->stack_a.content[0], data->reference[offset * 2], data->stack_a.content[offset * 3]);
		if (data->stack_a.content[0] >= data->reference[offset * 2] && data->stack_a.content[0] <= data->reference[offset * 3])
			push_b(data);
		else
			rotate_a(data);
		index++;
	}
	index = 0;
	while (index < data->num_args)
	{
	print_stack(data);
		ft_printf("a[0]: %i >= ref[%i] <= ref[%i]\n", data->stack_a.content[0], data->reference[offset * 3], data->stack_a.content[data->num_args - 4]);
		if (data->stack_a.content[0] >= data->reference[offset * 3] && data->stack_a.content[0] <= data->reference[data->num_args - 4])
			push_b(data);
		else
			rotate_a(data);
		index++;
	}
	print_stack(data);
	sort_three_num(data);
	while (data->stack_b.size > 0)
	{
		index = 0;
		min_index = find_big_number_index(data->stack_b);
		if (min_index < (data->stack_a.size / 2))
		{
			while (index < min_index)
			{
				rotate_b(data);
				index++;
			}
		}
		else 
		{
			while (index < data->stack_a.size - min_index)
			{
				reverse_rotate_b(data);
				index++;
			}
			
		}
		push_a(data);
	}
	// index = 0;
	// min_index = find_small_number_index(data->stack_a);
	// if (min_index > (data->num_args) / 2)
	// {
	// 	while (index < min_index - data->num_args)
	// 	{
	// 		reverse_rotate_a(data);
	// 		index++;
	// 	}
	// }
	return (0);
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

int	parse_referene(t_data *data)
{
	int index;

	index = 0;
	data->reference = calloc(data->num_args, sizeof(int));
	while (index < data->num_args)
	{
		data->reference[index] = data->stack_a.content[index];
		index++;
	}
	return (1);
}

int sort_reference(t_data *data)
{
	int index;
	int offset;
	int temp;

	offset = 0;
	while (offset < data->num_args)
	{
		index = 0;
		while (index < data->num_args - 1)
		{
			if (data->reference[index] > data->reference[index + 1])
			{
				temp = data->reference[index];
				data->reference[index] = data->reference[index + 1];
				data->reference[index + 1] = temp;
			}
			index++;
		}
		offset++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		error("too few arguments");
	parse_stacks(&data, argc - 1, argv);
	parse_referene(&data);
	sort_reference(&data);
	if (argc - 1 == 3)
		sort_three_num(&data);
	else if (argc - 1 == 5)
		sort_five_num(&data);
	else
		sort_algorithm(&data);
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
