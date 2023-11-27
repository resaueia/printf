/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:35:58 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:23 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>

void	putchar_print(char c)
{
	write(1, &c, 1);
	return (1);
}

void	putstr_print(char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		write(1, &s[index++], 1);
	return (index);
}

void	putnbr_print(int n)
{
	char	current_nbr;
	int	index;

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
		putnbr_print(n);
		index++;
	}
	else if (n <= 9)
	{
		current_nbr = n + 48;
		putchar_print(current_nbr);
	}
	else
	{
		putnbr_print(n / 10, fd);
		putnbr_print(n % 10, fd);
		index++;
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
		{
			format++;
			count++;
		}
		else if (*format == 'c')
		{
			count += putchar_print(va_start(args, const char *));
			format++;
		}
		else if (*format == 's')
		{
			count += putstr_print(va_start(args, const char *));
			format++;
		}
		else if (*format == 'p')
		{
		
		}
		else if (*format == 'd')
		{
		
		}
		else if (*format == 'i')
		{
			count += putnbr_print(va_start(args, int *))
		}
		else if (*format == 'u')
		{
		
		}
		else if (*format == 'x')
		{
		
		}
		else if (*format == 'X')
		{

		}
		else if (*format == '%')
			write (1, "%", 1);
		else
			ft_putchar_fd(&format);
		format++;
		va_end(args);
	}
	return (count);
}
