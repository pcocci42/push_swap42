/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:26:34 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/23 14:43:12 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	push_b(int *stack_a, int *stack_b, t_size *size)
{
	if (size->size_a > 0)
	{
		stack_b[size->size_b] = stack_a[size->size_a - 1];
		size->size_b++;
		size->size_a--;
	}
}

void	push_a(int *stack_a, int *stack_b, t_size *size)
{
	if (size->size_b > 0)
	{
		stack_a[size->size_a] = stack_b[size->size_b - 1];
		size->size_a++;
		size->size_b--;
	}
}

void	pa(int *stack_a, int *stack_b, t_size *size)
{
	push_a(stack_a, stack_b, size);
	write(1, "pa", 2);
	write(1, "\n", 1);
}

void	pb(int *stack_a, int *stack_b, t_size *size)
{
	push_b(stack_a, stack_b, size);
	write(1, "pb\n", 3);
}
