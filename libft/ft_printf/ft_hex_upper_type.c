/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_upper_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:04:02 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/05 17:29:14 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

int	hexadecimal_uppercase_output(va_list ap)
{
	unsigned int	place_holder;

	place_holder = (va_arg(ap, unsigned int));
	ft_putnbr_hexadecimal_uppercase_fd(place_holder, 1);
	return (count_hexa(place_holder));
}
