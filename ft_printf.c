/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:01:24 by hemottu           #+#    #+#             */
/*   Updated: 2022/12/16 19:45:02 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch(const char *str, va_list arg, int printed)
{
	str++;
	if (*str == 'c')
	{
		ft_putchar(va_arg(arg, int));
		printed++;
	}
	else if (*str == 's')
		printed = printed + ft_putstr(va_arg(arg, char *));
	else if (*str == 'p')
		printed = printed + ft_ptr(va_arg(arg, unsigned long));
	else if (*str == 'd' || *str == 'i')
		printed = printed + ft_putnbr(va_arg(arg, int));
	else if (*str == 'u')
		printed = printed + ft_putnbr_u(va_arg(arg, unsigned int));
	else if (*str == 'x' || *str == 'X')
		printed = printed + ft_putnbr_hexa(va_arg(arg, int), *str);
	else if (*str == '%')
	{
		ft_putchar('%');
		printed++;
	}
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			printed;

	printed = 0;
	if (str == NULL || *str == '\0')
		return (0);
	va_start (arg, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			ft_putchar(*str);
			printed++;
		}
		else if (*str == '%')
		{
			printed = ft_switch(str, arg, printed);
			str++;
		}
		str++;
	}
	va_end(arg);
	return (printed);
}
