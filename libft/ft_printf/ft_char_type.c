/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwallier <rwallier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:04:02 by rwallier          #+#    #+#             */
/*   Updated: 2022/09/05 17:22:56 by rwallier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"
#include "ft_printf.h"

int	char_output(va_list ap)
{
	char	place_holder;

	place_holder = (va_arg(ap, int));
	ft_putchar_fd(place_holder, 1);
	return (1);
}
