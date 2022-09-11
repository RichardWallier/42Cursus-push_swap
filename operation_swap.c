/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:14:06 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/11 14:26:11 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a_b(t_data *data)
{
	swap_a(data);
	swap_b(data);
	return (1);
}

int	swap_a(t_data *data)
{
	int	temp;

	if (data->stack_a.size < 2)
		return (0);
	temp = data->stack_a.content[0];
	data->stack_a.content[0] = data->stack_a.content[1];
	data->stack_a.content[1] = temp;
	return (1);
}

int	swap_b(t_data *data)
{
	int	temp;

	if (data->stack_b.size < 2)
		return (0);
	temp = data->stack_b.content[0];
	data->stack_b.content[0] = data->stack_b.content[1];
	data->stack_b.content[1] = temp;
	return (1);
}
