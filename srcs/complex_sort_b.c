/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:57:09 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/03 14:08:25 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int	min(int *stack, int size)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (++i < size)
	{
		if (stack[i] < stack[min])
			min = i;
	}
	return (min);
}

int	get_index_a(int n, int *stack, int size)
{
	int	i;
	int	index;

	i = -1;
	index = -1;
	while (++i < size)
	{
		if (index == -1)
		{
			if (stack[i] > n)
				index = i;
		}
		else
		{
			if (stack[i] > n && stack[i] < stack[index])
				index = i;
		}
	}
	if (index != -1)
		return (index);
	return (min(stack, size));
}

t_operations	count_m_b(int *stack_a, int *stack_b, t_size *size)
{
	t_operations	op;
	t_operations	min;
	int				i;
	int				index;

	i = size->size_b;
	while (--i >= 0)
	{
		fuck_bzero(&op, sizeof(t_operations));
		index = get_index_a(stack_b[i], stack_a, size->size_a);
		count_r(index, size->size_a, &op, 1);
		count_r(i, size->size_b, &op, 0);
		less_op(&op);
		if (i == size->size_b - 1 || diff(min, op))
			min = op;
	}
	return (min);
}

void	sort_b(int *stack_a, int *stack_b, t_size *size)
{
	t_operations	op;

	op = count_m_b(stack_a, stack_b, size);
	while (op.ra--)
		ra(stack_a, size);
	while (op.rb--)
		rb(stack_b, size);
	while (op.rr--)
		rotate_all(stack_a, stack_b, size);
	while (op.rra--)
		rra(stack_a, size);
	while (op.rrb--)
		rrb(stack_b, size);
	while (op.rrr--)
		rrr(stack_a, stack_b, size);
	pa(stack_a, stack_b, size);
}
