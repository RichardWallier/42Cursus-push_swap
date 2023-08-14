/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:00:53 by rwallier          #+#    #+#             */
/*   Updated: 2022/10/04 15:01:18 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(char *error_message, t_data *data)
{
	ft_printf("%s", error_message);
	if (data->stack_a.content)
		free(data->stack_a.content);
	if (data->stack_b.content)
		free(data->stack_b.content);
	if (data->reference)
		free(data->reference);
	exit(EXIT_FAILURE);
}

int	free_split(char **split)
{
	int	index;

	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
	return (0);
}

int	is_sorted(t_data *data)
{
	int	index;

	index = 0;
	while (index < data->stack_a.size - 1)
	{
		if (data->stack_a.content[index] > data->stack_a.content[index + 1])
			return (1);
		index++;
	}
	error("", data);
	return (0);
}
