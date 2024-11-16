/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:43:42 by brivera           #+#    #+#             */
/*   Updated: 2024/11/15 11:41:20 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdigit(long number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		write (1, "-", 1);
		number = number * -1;
		count = 1;
	}
	count = count + ft_putnbr_base((unsigned long)number, 10, 2);
	return (count);
}

int	ft_putdigit_unsigned(long number)
{
	unsigned long	unsigned_number;
	int				count;

	unsigned_number = (unsigned int)number;
	count = ft_putnbr_base(unsigned_number, 10, 2);
	return (count);
}

int	ft_putpointer(void *numpointer)
{
	int	count;

	count = 0;
	if (!numpointer)
	{
		return (ft_putstring("(nil)"));
	}
	else
	{
		write (1, "0x", 2);
		count = 2;
		count = count + ft_putnbr_base((unsigned long)numpointer, 16, 0);
	}
	return (count);
}

int	ft_puthexa_lowercase(long number)
{
	unsigned long	unsigned_number;
	int				count;

	unsigned_number = (unsigned int)number;
	count = ft_putnbr_base(unsigned_number, 16, 0);
	return (count);
}

int	ft_puthexa_uppercase(long number)
{
	unsigned long	unsigned_number;
	int				count;

	unsigned_number = (unsigned int)number;
	count = ft_putnbr_base(unsigned_number, 16, 1);
	return (count);
}
