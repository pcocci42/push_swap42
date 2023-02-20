/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:05:49 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:06 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	check_case(char c, int *n, va_list args)
{
	char_process(c, n, args);
	nb_process(c, n, args);
	nb_process_u(c, n, args);
	str_process(c, n, args);
	ptr_process(c, n, args);
	hex_process(c, n, args);
	percent_process(c, n);
	return (0);
}

void	vft_printf(const char *format, va_list args, int *n)
{
	while (*format != '\0')
	{
		if (*format != '%')
		{
			ft_putchar_n((char )*format, n);
		}
		else if (*format == '%')
		{
			format++;
			check_case(*format, n, args);
		}
		format++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		n;
	va_list	args;

	n = 0;
	va_start(args, format);
	vft_printf(format, args, &n);
	va_end(args);
	return (n);
}
