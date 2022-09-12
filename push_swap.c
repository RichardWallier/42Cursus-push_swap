/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/12 13:01:35 by rwallier         ###   ########.fr       */
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
		if (stack.content[index_max] > stack.content[index])
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
	int	min_index;

	index = 0;
	offset = 0;
	while (offset < data->num_args - 3)
	{
		min_index = find_small_number_index(data->stack_a);
		index = 0;
		while (index < min_index)
		{
			choose_call("ra", data);
			index++;
		}
		choose_call("pb", data);
		offset++;
	}
	sort_three_num(data);
	offset = 0;
	while (offset < data->num_args - 3)
	{
		choose_call("pa", data);
		offset++;
	}
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

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		error("too few arguments");
	parse_stacks(&data, argc - 1, argv);
	if (argc - 1 == 3)
		sort_three_num(&data);
	else if (argc - 1 == 5)
		sort_five_num(&data);
	else
		sort_algorithm(&data);
	// manual_sorting(&data);
	// ft_printf("\n\n--------FINAL STACK-------\n\n");
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
