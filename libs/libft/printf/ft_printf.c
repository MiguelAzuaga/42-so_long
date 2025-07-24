/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueiros <mqueiros@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 10:26:24 by mqueiros          #+#    #+#             */
/*   Updated: 2025/07/17 07:04:04 by mqueiros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>

int	ft_putflag(va_list args, const char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int), 0));
	else if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int), 1));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c == 'x'));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	lst_arg;
	size_t	i;
	size_t	len;

	if (!str)
		return (-1);
	va_start(lst_arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len += ft_putflag(lst_arg, str[++i]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end(lst_arg);
	return (len);
}
