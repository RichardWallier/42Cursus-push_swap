/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/11 17:37:21 by rwallier         ###   ########.fr       */
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
	// ft_printf("min index: %i\n", index_max);
	return (index_max);
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

int	sort_algorithm(t_data *data)
{
	int	index;
	int	offset;
	int	min_index;

	index = 0;
	offset = 0;
	while (offset < data->num_args)
	{
		min_index = find_big_number_index(data->stack_a);
		// print_stack(data);
		index = 0;
		while (index < min_index)
		{
			choose_operation("ra", data);
			ft_printf("ra\n");
			index++;
		}
		choose_operation("pb", data);
		ft_printf("pb\n");
		offset++;
	}
	// choose_operation("ra", data);
	// choose_operation("sa", data);
	offset = 0;
	while (offset < data->num_args)
	{
		// print_stack(data);
		choose_operation("pa", data);
		ft_printf("pa\n");
		offset++;
	}
	return (0);
}

int	manual_sorting(t_data *data)
{
	int index;
	char *operation;

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
		operation = get_next_line(0);
		ft_printf("\n-----------> operation: %s", operation);
		choose_operation(operation, data);
		free (operation);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc < 2)
		error("too few arguments");
	parse_stacks(&data, argc - 1, argv);
	sort_algorithm(&data);
	// manual_sorting(&data);
	// ft_printf("\n\n--------FINAL STACK-------\n\n");
	// print_stack(&data);
	free(data.stack_a.content);
	free(data.stack_b.content);
	return (0);
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
