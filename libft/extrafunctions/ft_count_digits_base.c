/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 15:06:50 by rwallier          #+#    #+#             */
/*   Updated: 2022/10/04 15:06:51 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_digits_base(long long int number, int base)
{
	int	index;

	index = 0;
	if (!number)
		return (1);
	while (number != 0)
	{
		index++;
		number /= base;
	}
	return (index);
}
