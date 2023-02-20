/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:06:14 by pcocci            #+#    #+#             */
/*   Updated: 2023/01/10 13:59:06 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	hex_digit(int nb)
{
	if (nb >= 0 && nb < 10)
		return ('0' + nb);
	else
		return ('a' + nb - 10);
}

int	hex_null(void *p0, int *n)
{
	if (p0 == NULL)
	{
		ft_putstr_n("(nil)", n);
		return (0);
	}
	return (1);
}

void	put_address(int j, int *n, char *hex)
{
	while (hex[j] == '0')
		j++;
	while (hex[j] != '\0')
	{
		ft_putchar_n(hex[j], n);
		j++;
	}
}

void	print_address_hex(void *p0, int *n)
{
	int			i;
	int			j;
	char		*hex;
	uintptr_t	p;

	hex = malloc(sizeof(char *));
	j = 0;
	p = (uintptr_t)p0;
	i = (sizeof(p) << 3) - 4;
	if (hex_null(p0, n) == 1)
	{
		ft_putchar_n('0', n);
		ft_putchar_n('x', n);
		while (i >= 0)
		{
			hex[j] = hex_digit((p >> i) & 0xf);
			j++;
			i -= 4;
		}
		j = 0;
		put_address(j, n, hex);
	}
	free(hex);
}
