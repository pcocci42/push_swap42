/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:23:43 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 10:24:59 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	swap_a(int *stack, t_size *size)
{
	int	tmp;

	if (size->size_a > 1)
	{
		tmp = stack[size->size_a - 1];
		stack[size->size_a - 1] = stack[size->size_a - 2];
		stack[size->size_a - 2] = tmp;
	}
}

void	sa(int *stack, t_size *size)
{
	swap_a(stack, size);
	write(1, "sa\n", 3);
}

void	swap_b(int *stack, t_size *size)
{
	int	tmp;

	if (size->size_b > 1)
	{
		tmp = stack[size->size_b - 1];
		stack[size->size_b - 1] = stack[size->size_b - 2];
		stack[size->size_b - 2] = tmp;
	}
}

void	sb(int *stack, t_size *size)
{
	swap_b(stack, size);
	write(1, "sb\n", 3);
}

void	swap_all(int *stack_a, int *stack_b, t_size *size)
{
	swap_a(stack_a, size);
	swap_b(stack_b, size);
	write(1, "ss\n", 3);
}
