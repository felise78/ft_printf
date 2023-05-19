/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hemottu <hemottu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:14:49 by hemottu           #+#    #+#             */
/*   Updated: 2023/05/19 11:09:43 by hemottu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h> 
# include <stddef.h>
# include <unistd.h> 
# include <stdarg.h> 
# include <sys/types.h>
# include <limits.h>

void	ft_putchar(char c);
int		ft_printf(const char *str, ...);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
int		ft_putnbr_u(unsigned int n);
int		ft_putnbr_hexa(unsigned int c, const char format);
int		ft_ptr(unsigned long n);

#endif
