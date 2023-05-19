/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:25 by hemottu           #+#    #+#             */
/*   Updated: 2022/12/16 15:11:50 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len(unsigned int n)
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

int	ft_putnbr_hexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_putnbr_hexa((n / 16), format);
		ft_putnbr_hexa((n % 16), format);
	}
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
	return (ft_len(n));
}
