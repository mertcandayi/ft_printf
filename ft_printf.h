/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi <medayi@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:53:21 by medayi            #+#    #+#             */
/*   Updated: 2024/11/14 21:22:27 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

int ft_printf(const char *format, ...);
int ft_putchar(int x);
int ft_putstr(char *str);
int ft_putnbr(long x);
int ft_puthex(unsigned long x, int type);
int ft_point(void *ptr);

#endif
