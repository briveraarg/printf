/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:48:58 by brivera           #+#    #+#             */
/*   Updated: 2024/11/13 18:18:28 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long nbr, int base, int type_digits)
{
	char	*hexa_lowercase;
	char	*hex_uppercase;
	char	*base_num;
	char	buffer[65];
	int		i;

	hexa_lowercase = "0123456789abcdef";
	hex_uppercase = "0123456789ABCDEF";
	if (nbr == 0)
		return (write(1, "0", 1), 1);
	i = 65;
	buffer[i] = '\0';
	if (type_digits == 1)
		base_num = hex_uppercase;
	else if (type_digits == 0)
		base_num = hexa_lowercase;
	else if (type_digits == 2)
		base_num = "0123456789";
	while (nbr != 0)
	{
		buffer[--i] = base_num[nbr % base];
		nbr = nbr / base;
	}
	write(1, &buffer[i], 65 - i);
	return (65 - i);
}
