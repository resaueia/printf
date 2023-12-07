/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:03:38 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/06 16:13:04 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		return (putstr_print("(null)"));
	while (s[index])
		write(1, &s[index++], 1);
	return (index);
}

int	putnbr_print_hex(unsigned long int n, unsigned int base, int type)
{
	int		index;
	char	*symbols;

	index = 0;
	if (type == 1)
		symbols = "0123456789abcdef";
	if (type == 2)
		symbols = "0123456789ABCDEF";
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
		index += putchar_print('-');
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
		index += putnbr_unsigned(n / 10);
		index += putnbr_unsigned(n % 10);
	}
	else
		index += putchar_print(n + 48);
	return (index);
}
