/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:12:37 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/11 14:22:49 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_data *data)
{
	int	index;
	int	temp;

	temp = data->stack_a.content[0];
	index = 0;
	while (index < data->stack_a.size)
	{
		data->stack_a.content[index] = data->stack_a.content[index + 1];
		index++;
	}
	data->stack_a.content[data->stack_a.size - 1] = temp;
	return (1);
}

int	rotate_b(t_data *data)
{
	int	index;
	int	temp;

	temp = data->stack_b.content[0];
	index = 0;
	while (index < data->stack_b.size)
	{
		data->stack_b.content[index] = data->stack_b.content[index + 1];
		index++;
	}
	data->stack_b.content[data->stack_b.size - 1] = temp;
	return (1);
}

int	rotate_a_b(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
	return (1);
}
