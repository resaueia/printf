/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:58 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/11/28 20:02:17 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

int	putchar_print(char c)
{
	write(1, &c, 1);
	return (1);
}

int	putstr_print(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		write(1, &s[index++], 1);
	return (index);
}

int	putnbr_print(long n, int base)
{
	int	index;
	char	*symbols;

	symbols = "0123456789abcdef";
	index = 0;
	if (n == -2147483648)
	{
		putstr_print("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		n = n * (-1);
		putchar_print('-');
		putnbr_print(symbols[n]);
		index++;
	}
	else if (n <= base)
	{
		putchar_print(symbols[n]);
	}
	else
	{
		index = putnbr_print(n / base);
		putnbr_print(n % base);
	}
	return (index);
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
			format++;
		else if (*format == 'c')
			count += putchar_print(va_arg(args, const char *));
		else if (*format == 's')
			count += putstr_print(va_arg(args, const char *));
		else if (*format == 'p')
		{
		
		}
		else if (*format == 'd')
			count += putnbr(va_arg(args, (long)int n, 10));
		else if (*format == 'i')
			count += putnbr_print(va_arg(args, (long)int n, 10));
		else if (*format == 'u')
			count += putnbr_print(va_arg(args, (unsigned long)int n, 10));
		else if (*format == 'x')

		else if (*format == 'X')

		else if (*format == '%')
			write (1, "%", 1);
		else
			ft_putchar_fd(*format);
		format++;
		va_end(args);
	}
	return (count);
}
