/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:23:01 by hemottu           #+#    #+#             */
/*   Updated: 2022/12/16 15:09:03 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len(unsigned long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n > 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

static int	ft_hexa(unsigned long n)
{
	if (n >= 16)
	{
		ft_hexa(n / 16);
		ft_hexa(n % 16);
	}
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	return (ft_len(n));
}

int	ft_ptr(unsigned long n)
{
	int	printed;

	if (!n)
	{
		ft_putstr("(nil)");
		return (5);
	}
	printed = ft_putstr("0x");
	printed += ft_hexa(n);
	return (printed);
}
