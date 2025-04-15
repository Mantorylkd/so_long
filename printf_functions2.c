/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:26:59 by ekhallaf          #+#    #+#             */
/*   Updated: 2024/12/24 00:28:19 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_puthex(unsigned int nb, char format, int *count)
{
	char	*base;

	base = NULL;
	if (format == 'x')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (nb >= 16)
		ft_puthex(nb / 16, format, count);
	ft_putchar(base[nb % 16], count);
}

void	ft_putuint(unsigned int nb, int *counter)
{
	if (nb > 9)
		ft_putuint(nb / 10, counter);
	ft_putchar((nb % 10) + '0', counter);
}
