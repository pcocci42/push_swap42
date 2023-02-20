/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:05:19 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:58:17 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	char_process(char c, int *n, va_list args)
{
	char	ch;

	if (c == 'c')
	{
		ch = va_arg(args, int);
		ft_putchar_n(ch, n);
	}
}
