/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:50:12 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/30 17:50:13 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
