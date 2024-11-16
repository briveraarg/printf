/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:41:18 by brivera           #+#    #+#             */
/*   Updated: 2024/11/13 18:18:24 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstring(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstring("(null)"));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
