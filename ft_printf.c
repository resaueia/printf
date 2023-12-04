/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:58 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/04 19:35:26 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	putchar_print(int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_print(const char *s)
{
	size_t	index;

	index = 0;
	if (!s)
		return (putstr_print(0));
	while (s[index])
		write(1, &s[index++], 1);
	return (index);
}

int	putnbr_print_hex(long long n, int base, int type)
{
	int	index;
	char	*symbols;

	index = 0;
	if (type == 1)
		symbols = "0123456789abcdef";
	if (type == 2)
		symbols = "0123456789ABCDEF";
	if (type == 3)
	{
		type = 1;
		putstr_print("0x");
	}
	if (n >= base)
	{
		index += putnbr_print_hex(n / base, base, type);
		index += putnbr_print_hex(n % base, base, type);
	}
	else
		index += putchar_print(symbols[n]);
	return (index);
}

int	putnbr_print_dec(long n, int base)
{
	int	index;

	index = 0;
	if (n < 0)
	{
		n = n * (-1);
		putchar_print('-');
		index++;
	}
	if (n >= base)
	{
		index += putnbr_print_dec(n / base, base);
		index += putnbr_print_dec(n % base, base);
	}
	else
		index += putchar_print(n + 48);
	return (index);
}

int	putnbr_unsigned(unsigned long int n)
{
	int	index;

	index = 0;
	if (n >= 10)
	{
		index+= putnbr_unsigned(n / 10);
		index += putnbr_unsigned(n % 10);
	}
	else
		index += putchar_print(n + 48);
}
*/
int	arg_checker(char checker, va_list args)
{
	int	count;

	count = 0;
	if (checker == 'c')
		count += putchar_print(va_arg(args, int));
	else if (checker == 's')
		count += putstr_print(va_arg(args, const char *));
	else if (checker == 'p')
		count += putnbr_print_hex(va_arg(args, long int), 16, 3);
	else if (checker == 'd')
		count += putnbr_print_dec(va_arg(args, long int), 10);
	else if (checker == 'i')
		count += putnbr_print_dec(va_arg(args, long int), 10);
	else if (checker == 'u')
		count += putnbr_unsigned(va_arg(args, unsigned long int));
	else if (checker == 'x')
		count += putnbr_print_hex(va_arg(args, long int), 16, 1);
	else if (checker == 'X')
		count += putnbr_print_hex(va_arg(args, long int), 16, 2);
	else if (checker == '%')
		count += putchar_print('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += arg_checker(*format, args);
			/*if (*format == 'c')
				count += putchar_print(va_arg(args, int));
			else if (*format == 's')
				count += putstr_print(va_arg(args, const char *));
			else if (*format == 'p')
				count += putnbr_print_hex(va_arg(args, long int), 16, 3);
			else if (*format == 'd' || *format == 'i')
				count += putnbr_print_dec(va_arg(args, long int), 10);
			else if (*format == 'u')
				count += putnbr_unsigned(va_arg(args, unsigned long int));
			else if (*format == 'x')
				count += putnbr_print_hex(va_arg(args, long int), 16, 1);
			else if (*format == 'X')
				count += putnbr_print_hex(va_arg(args, long int), 16, 2);
			else if (*format == '%')
				putchar_print('%');*/
		}
		else
			count += putchar_print(*format);
		format++;
	}
	va_end(args);
	return (count);
}

/*
int	main(void)
{
	int	a;
	int	*ptr;

	a = 10;
	ptr = &a;
	ft_printf("Hello, my name is %s, and I am %i years old.\n", "Ezequiel", 47);
	ft_printf("Hello, my name is %c, and I am %d years old.\n", 'E', 47);
	ft_printf("Hello, my name is %x, and I am %X years old.\n", 42, 42);
	printf("Hello, my name is %x, and I am %X years old.\n", 42, 42);
	ft_printf("Hello, my name is %p, and I am %X years old.\n", ptr, 42);
	printf("Hello, my name is %p, and I am %X years old.\n", ptr, 42);
}*/
