/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 04:58:13 by ekhallaf          #+#    #+#             */
/*   Updated: 2024/12/25 15:50:09 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	conv(const char *format, va_list args, int *counter)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), counter);
	else if (*format == 's')
		ft_putstr(va_arg(args, char *), counter);
	else if (*format == 'p')
		ft_putptr(va_arg(args, void *), counter);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(args, int), counter);
	else if (*format == 'u')
		ft_putuint(va_arg(args, unsigned int), counter);
	else if (*format == 'x' || *format == 'X')
		ft_puthex(va_arg(args, unsigned int), *format, counter);
	else if (*format == '%')
		ft_putchar('%', counter);
	else
		*counter = -1;
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	if (format == NULL)
		return (-1);
	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			conv(format, args, &counter);
			if (counter == -1)
			{
				va_end(args);
				return (-1);
			}
		}
		else
			ft_putchar(*format, &counter);
		format++;
	}
	va_end(args);
	return (counter);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int i = printf("%\n");
// 	printf("%d\n", i);

// 	int j = ft_printf("%\n");
// 	printf("%d\n", j);
// }