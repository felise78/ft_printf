/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:35:32 by hemottu           #+#    #+#             */
/*   Updated: 2022/12/15 14:44:16 by hemottu          ###   ########.fr       */
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
		n = n / 10;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int n)
{
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n >= 10)
	{
		ft_putnbr_u(n / 10);
		ft_putnbr_u(n % 10);
	}
	return (ft_len(n));
}
