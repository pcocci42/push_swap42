/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:07:36 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:12 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ptr_process(char c, int *n, va_list args)
{
	void	*p0;

	if (c == 'p')
	{
		p0 = va_arg(args, void *);
		print_address_hex(p0, n);
	}
}
