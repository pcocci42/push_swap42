/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:06:23 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:08 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	hex_process(char c, int *n, va_list args)
{
	int	nb;

	if (c == 'x' || c == 'X')
	{
		nb = va_arg(args, int);
		if (c == 'x')
			ft_putnbr_base_u(nb, "0123456789abcdef", n);
		else if (c == 'X')
			ft_putnbr_base_u(nb, "0123456789ABCDEF", n);
	}
}
