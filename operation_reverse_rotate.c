/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:10:31 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/14 19:28:03 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	reverse_rotate_a(t_data *data)
{
	ft_printf("teste\n");
	int	index;
	int	temp;

	temp = data->stack_a.content[data->stack_a.size - 1];
	index = data->stack_a.size - 1;
	while (index > 0)
	{
		data->stack_a.content[index] = data->stack_a.content[index - 1];
		index--;
	}
	data->stack_a.content[0] = temp;
	return (1);
}

int	reverse_rotate_b(t_data *data)
{
	ft_printf("teste\n");
	int	index;
	int	temp;

	temp = data->stack_b.content[data->stack_b.size - 1];
	index = data->stack_b.size - 1;
	while (index > 0)
	{
		data->stack_b.content[index] = data->stack_b.content[index - 1];
		index--;
	}
	data->stack_b.content[0] = temp;
	return (1);
}

int	reverse_rotate_a_b(t_data *data)
{
	ft_printf("teste");

	reverse_rotate_a(data);
	reverse_rotate_b(data);
	return (1);
}
