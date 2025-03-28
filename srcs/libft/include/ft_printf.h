/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analexan <analexan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:29:42 by jealves-          #+#    #+#             */
/*   Updated: 2024/02/03 11:35:19 by analexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# define HEXA_LOWER "0123456789abcdef"
# define HEXA_UPPER "0123456789ABCDEF"
# define DECIMAL "0123456789"

int	prt(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putpointer(unsigned long int n);
int	ft_putnbr_base(long int n, char *base);
int	ft_putnbr_base_us(unsigned long int n, char *base);

#endif
