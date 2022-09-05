/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:49:33 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/05 17:46:16 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "get_next_line.h"

size_t	next_nl(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] != '\n')
	{
		if (!buffer[index])
			return (0);
		index++;
	}
	return (1);
}

size_t	end_line(char *buffer)
{
	int	index;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	return (index);
}
