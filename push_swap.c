/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/05 19:12:05 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_operation(char *operation, t_data *data)
{
	if (ft_strnstr(operation, "sa", ft_strlen(operation)))
		swap_a(data);
	else if (ft_strnstr(operation, "sb", ft_strlen(operation)))
		swap_b(data);
	else if (ft_strnstr(operation, "ss", ft_strlen(operation)))
		swap_a_b(data);
	return (1);
}

int	swap_a_b(t_data *data)
{
	ft_printf("\n-----------operation: ss-------------");
	swap_a(data);
	swap_b(data);
	return (1);
}

int	swap_a(t_data *data)
{
	int	temp;

	ft_printf("\n-----------operation: sa-------------");
	if (data->stack_size < 2)
	{
		ft_printf("Do nothing if there is only one or no elements.\n");
		return (0);
	}
	temp = data->stack_a[0];
	data->stack_a[0] = data->stack_a[1];
	data->stack_a[1] = temp;
	return (1);
}

int	swap_b(t_data *data)
{
	int	temp;

	ft_printf("\n-----------operation: sb-------------");
	if (data->stack_size < 2)
	{
		ft_printf("Do nothing if there is only one or no elements.\n");
		return (0);
	}
	temp = data->stack_b[0];
	data->stack_b[0] = data->stack_b[1];
	data->stack_b[1] = temp;
	return (1);
}

int	push_a(t_data *data)
{

	return (1);
}

int	parse_stacks(t_data *data, size_t size, char *argv[])
{
	size_t index;

	data->stack_size = size;
	data->stack_a = ft_calloc(size, sizeof(int));
	data->stack_b = ft_calloc(size, sizeof(int));
	index = 0;
	while (index < size)
	{
		data->stack_a[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int	index;
	char *operation;

	if (argc < 2)
		error("too few arguments");
	parse_stacks(&data, argc - 1, argv);
	index = 0;
	while (1)
	{
		index = 0;
		ft_putendl_fd("", 1);
		while (index < argc -1)
		{
			ft_printf("stack_a[%i]: %i || stack_b[%i]: %i\n", index, data.stack_a[index],
			index, data.stack_b[index]);
			index++;
		}
		operation = get_next_line(0);
		choose_operation(operation, &data);
		free (operation);
	}
	free(data.stack_a);
	free(data.stack_b);
	return (0);
}

int	error(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(EXIT_FAILURE);
}
