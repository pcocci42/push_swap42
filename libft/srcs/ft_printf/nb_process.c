/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:07:00 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:09 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	nb_process(char c, int *n, va_list args)
{
	int	nb;

	if (c == 'd' || c == 'i')
	{
		nb = va_arg(args, int);
		ft_putnbr_n(nb, n);
	}
}
