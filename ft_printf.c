/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:36:56 by brivera           #+#    #+#             */
/*   Updated: 2024/11/15 16:41:35 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_what_format_is(char specifier, va_list argument)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(argument, int)));
	else if (specifier == 's')
		return (ft_putstring(va_arg(argument, char *)));
	else if (specifier == 'p')
		return (ft_putpointer(va_arg(argument, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putdigit(va_arg(argument, int)));
	else if (specifier == 'u')
		return (ft_putdigit_unsigned(va_arg(argument, int)));
	else if (specifier == 'x')
		return (ft_puthexa_lowercase(va_arg(argument, int)));
	else if (specifier == 'X')
		return (ft_puthexa_uppercase(va_arg(argument, int)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	else
		return (-1);
}

static int	ft_format_char(const char *format, int *i, va_list argument)
{
	int	result;

	if (format[*i] == '%' && format[*i + 1] == '\0')
		return (-1);
	else if (format[*i] == '%' && format[*i + 1])
	{
		(*i)++;
		result = ft_what_format_is(format[*i], argument);
		if (result == -1)
			return (-1);
		return (result);
	}
	else
	{
		write(1, &format[*i], 1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	argument;
	int		count;
	int		result;
	int		i;

	count = 0;
	i = 0;
	va_start(argument, format);
	while (format[i])
	{
		result = ft_format_char(format, &i, argument);
		if (result == -1)
		{
			va_end(argument);
			return (-1);
		}
		count += result;
		i++;
	}
	va_end(argument);
	return (count);
}
