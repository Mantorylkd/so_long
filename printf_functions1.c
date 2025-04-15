/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:03:21 by ekhallaf          #+#    #+#             */
/*   Updated: 2024/12/25 15:17:02 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar(*str, counter);
		str++;
	}
}

void	ft_putnbr(int nb, int *counter)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", counter);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-', counter);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr((nb / 10), counter);
	ft_putchar(('0' + nb % 10), counter);
}

static void	ft_put_hex_ptr(unsigned long ptr, int *counter)
{
	if (ptr >= 16)
	{
		ft_put_hex_ptr(ptr / 16, counter);
		ft_put_hex_ptr(ptr % 16, counter);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar((ptr + '0'), counter);
		else
			ft_putchar((ptr - 10 + 'a'), counter);
	}
}

void	ft_putptr(void *a, int *counter)
{
	unsigned long	ap;

	ap = (unsigned long)a;
	if (!ap)
	{
		ft_putstr("(nil)", counter);
		return ;
	}
	ft_putstr("0x", counter);
	ft_put_hex_ptr(ap, counter);
}

// int main()
// {
// 	size_t count = 0;
// 	int nb = 42;
// 	void *ptr = &nb;
// 	ft_putptr_pf(ptr,&count);
// } 
