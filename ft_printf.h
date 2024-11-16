/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:52:07 by brivera           #+#    #+#             */
/*   Updated: 2024/11/15 16:43:59 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char const *formato, ...);
int		ft_putchar(char c);
int		ft_putstring(char *s);
int		ft_putdigit(long number);
int		ft_putdigit_unsigned(long number);
int		ft_putpointer(void *numpointer);
int		ft_puthexa_lowercase(long number);
int		ft_puthexa_uppercase(long number);
int		ft_putnbr_base(unsigned long nbr, int base, int is_uppercase);
#endif