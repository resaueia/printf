/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:55:24 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/05 20:08:23 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	putchar_print(int c);
int	putstr_print(const char *s);
int	putnbr_print_hex(unsigned long int n, unsigned int base, int type);
int	vipointer(unsigned long int n);
int	putnbr_print_dec(long n, int base);
int	putnbr_unsigned(unsigned long int n);
int	arg_checker(char checker, va_list args);
int	ft_printf(const char *format, ...);

#endif
