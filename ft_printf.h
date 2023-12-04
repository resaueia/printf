/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:55:24 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/04 19:02:55 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	putchar_print(int c);
int	putstr_print(const char *s);
int	putnbr_print_hex(long long n, int base, int type);
int	putnbr_print_dec(long n, int base);
int	putnbr_unsigned(unsigned long int);
int	arg_checker(char checker, va_list args);
int	ft_printf(const char *format, ...);

#endif
