/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:14:53 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/30 17:50:40 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf/ft_printf.h"
#include "push_swap.h"

int	parse_stacks(t_data *data, size_t size, char *argv[])
{
	if (size == 1)
		populate_string(data, argv);
	else
		populate_args(data, size, argv);
	return (1);
}

int	populate_string(t_data *data, char *argv[])
{
	size_t	index;
	size_t	aux;
	char	**split;

	split = ft_split(argv[1], ' ');
	data->stack_a.content = ft_calloc(split_len(split), sizeof(int));
	data->stack_b.content = ft_calloc(split_len(split), sizeof(int));
	index = 0;
	while (split[index])
	{
		aux = 0;
		while (aux < ft_strlen(split[index]))
		{
			if (!ft_isdigit(split[index][aux]))
				return (0);
			aux++;
		}
		data->stack_a.content[index] = ft_atoi(split[index]);
		index++;
	}
	data->stack_a.size = index;
	data->num_args = index;
	return (1);
}

int	populate_args(t_data *data, size_t size, char *argv[])
{
	size_t	index;
	size_t	aux;

	data->stack_a.content = ft_calloc(size, sizeof(int));
	data->stack_b.content = ft_calloc(size, sizeof(int));
	index = 0;
	while (index < size)
	{
		aux = 0;
		while (aux < ft_strlen(argv[index + 1]))
		{
			if (!ft_isdigit(argv[index + 1][aux]))
				return (0);
			aux++;
		}
		data->stack_a.content[index] = ft_atoi(argv[index + 1]);
		index++;
	}
	data->num_args = index;
	data->stack_a.size = index;
	return (1);
}

int	parse_referene(t_data *data)
{
	int	index;

	index = 0;
	data->reference = calloc(data->num_args, sizeof(int));
	while (index < data->num_args)
	{
		data->reference[index] = data->stack_a.content[index];
		index++;
	}
	return (1);
}
