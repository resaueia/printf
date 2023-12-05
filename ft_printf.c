/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:58 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/05 19:44:39 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_checker(char checker, va_list args)
{
	int	count;

	count = 0;
	if (checker == 'c')
		count = putchar_print(va_arg(args, int));
	else if (checker == 's')
		count = putstr_print(va_arg(args, const char *));
	else if (checker == 'p')
		count = vipointer(va_arg(args, unsigned long int));
	else if (checker == 'd')
		count = putnbr_print_dec(va_arg(args, int), 10);
	else if (checker == 'i')
		count = putnbr_print_dec(va_arg(args, int), 10);
	else if (checker == 'u')
		count = putnbr_unsigned(va_arg(args, unsigned int));
	else if (checker == 'x')
		count = putnbr_print_hex(va_arg(args, unsigned int), 16, 1);
	else if (checker == 'X')
		count = putnbr_print_hex(va_arg(args, unsigned int), 16, 2);
	else if (checker == '%')
		count = putchar_print('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += arg_checker(*format, args);
		}
		else
			count += putchar_print((char)*format);
		format++;
	}
	va_end(args);
	return (count);
}
