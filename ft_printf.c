/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi <medayi@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:53:21 by medayi            #+#    #+#             */
/*   Updated: 2024/11/14 21:21:02 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int ft_form(va_list args, char formtype)
{
    int len;

    len = 0;
    if (formtype == 'i' || formtype == 'd')
        len += ft_putnbr(va_arg(args, int));
    else if (formtype == 'c')
        len += ft_putchar(va_arg(args, int));
    else if (formtype == 's')
        len += ft_putstr(va_arg(args, char *));
    else if (formtype == 'p')
        len += ft_point(va_arg(args, void *));
    else if (formtype == 'u')
        len += ft_putnbr(va_arg(args, unsigned int));
    else if (formtype == 'x')
        len += ft_puthex(va_arg(args, unsigned long), 0);
    else if (formtype == 'X')
        len += ft_puthex(va_arg(args, unsigned long), 1);
    else if (formtype == '%')
        len += ft_putchar('%');
    else if (!formtype)
        len += ft_putstr("(null)");
    return (len);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int len;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            len += ft_form(args, format[i + 1]);
            i++;
        }
        else
            len += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return (len);
}
