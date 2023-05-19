/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:12:57 by hemottu           #+#    #+#             */
/*   Updated: 2022/12/16 15:13:30 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	else if (n == -2147483648)
		len = 11;
	else if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr((n * (-1)));
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	return (ft_len(n));
}
