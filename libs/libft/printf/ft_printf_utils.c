/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:31:35 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/17 07:03:55 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = 0;
	while (str[len])
		ft_putchar(str[len++]);
	return (len);
}

int	ft_puthex(unsigned long num, int lowercase)
{
	int			i;
	int			len;
	const char	*base;
	char		buffer[16];

	if (lowercase)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (num == 0)
		return (ft_putchar ('0'));
	i = 0;
	while (num > 0)
	{
		buffer[i] = base[num % 16];
		num /= 16;
		i++;
	}
	len = i;
	while (i--)
		ft_putchar(buffer[i]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
	write(1, "0x", 2);
	len = 2;
	len += ft_puthex((unsigned long)ptr, 1);
	return (len);
}

int	ft_putnbr(long num, int is_unsigned)
{
	int	len;

	len = 0;
	if (!is_unsigned)
	{
		if (num == -2147483648)
		{
			len += ft_putstr("-2147483648");
			return (len);
		}
		if (num < 0)
		{
			len += ft_putchar('-');
			num *= -1;
		}
	}
	if (num > 9)
	{
		len += ft_putnbr(num / 10, is_unsigned);
	}
	len += ft_putchar((num % 10) + '0');
	return (len);
}
