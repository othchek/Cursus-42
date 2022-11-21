/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:03:50 by otchekai          #+#    #+#             */
/*   Updated: 2022/11/21 15:00:55 by otchekai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int     ft_putstr(char *s);
int		ft_putnbr(int n);
int     ft_putchar(char c);
int		ft_countlen(long int nmb);
int     ft_print_unsigned(unsigned int i);
int     ft_puthex(size_t i);
int     ft_puthexup(size_t i);
int     ft_putadd(unsigned long long);

#endif