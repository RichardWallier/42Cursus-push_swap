/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:36:46 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/30 17:49:32 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->num_args)
	{
		ft_printf("stack_a[%i]: %i || stack_b[%i]: %i\n", index,
			data->stack_a.content[index],
			index, data->stack_b.content[index]);
		index++;
	}
	ft_printf("\n\n");
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (!parse_stacks(&data, argc - 1, argv))
		exit (ft_printf("Error\n"));
	parse_referene(&data);
	sort_reference(&data);
	if (data.num_args == 3)
		sort_three_num(&data);
	else if (data.num_args == 5)
		sort_five_num(&data);
	else if (data.num_args <= 200)
		sort_algorithm(&data, 4);
	else
		sort_algorithm(&data, 15);
	free(data.stack_a.content);
	free(data.stack_b.content);
	return (0);
}
