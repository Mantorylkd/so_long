/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekhallaf <ekhallaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:38:31 by ekhallaf          #+#    #+#             */
/*   Updated: 2025/04/15 16:32:11 by ekhallaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int     ft_printf(const char *format, ...);
void	ft_putstr(char *str, int *counter);
void	ft_putchar(char c, int *count);
void	ft_putnbr(int nb, int *counter);
void	ft_puthex(unsigned int nb, char format, int *count);
void	ft_putuint(unsigned int nb, int *counter);
// static void	ft_put_hex_ptr(unsigned long ptr, int *counter);
void	ft_putptr(void *a, int *counter);

#endif