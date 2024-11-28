/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:15:49 by medayi            #+#    #+#             */
/*   Updated: 2024/11/26 22:15:49 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(int x)
{
    write(1, &x, 1);
    return (1);
}

int ft_putstr(char *str)
{
    int len;

    len = 0;
    if (!str)
    {
        return(write(1, "(null)", 6));
    }
    while (str[len])
        len += ft_putchar(str[len]);
    return (len);
}

int ft_putnbr(long x)
{
    int len;

    len = 0;
    if (x == -2147483648)
    {
        len = ft_putstr("-2147483648");
        return (len);
    }
    if (x < 0)
    {
        len += ft_putchar('-');
        x = -x;
    }
    if (x >= 10)
        len += ft_putnbr(x / 10);
    len += ft_putchar((x % 10) + 48);
    return (len);
}

int ft_puthex(unsigned long x, int type)
{
    int len;
    char *hex_type;

    len = 0;
    if (type == 1)
        hex_type = "0123456789ABCDEF";
    else
        hex_type = "0123456789abcdef";
    if (x >= 16)
        len += ft_puthex(x / 16, type);
    len += ft_putchar(hex_type[x % 16]);
    return (len);
}

int ft_point(void *ptr)
{
    int len;

    len = 0;
    if (!ptr)
    {
        len += ft_putstr("(nil)");
        return (len);
    }
    len += ft_putstr("0x");
    len += ft_puthex((unsigned long)ptr, 0);
    return (len);
}
