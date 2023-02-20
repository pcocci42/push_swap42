/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:07:13 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:08 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	nb_process_u(char c, int *n, va_list args)
{
	unsigned int	nb;

	if (c == 'u' )
	{
		nb = va_arg(args, unsigned int);
		ft_putnbr_u(nb, n);
	}
}
