/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:34:58 by rsaueia-          #+#    #+#             */
/*   Updated: 2023/12/05 19:39:57 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	vipointer(unsigned long int n)
{
	int	index;

	index = 0;
	if (!n)
		return (putstr_print("(nil)"));
	index += putstr_print("0x");
	index += putnbr_print_hex(n, 16, 1);
	return (index);
}
