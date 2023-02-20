/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:25:35 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 10:26:00 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	reverse_ra(int *stack, t_size *size)
{
	int		*tmp;
	int		i;

	if (size->size_a > 1)
	{
		tmp = malloc(size->size_a * sizeof(int));
		i = -1;
		while (++i < size->size_a)
			tmp[i] = stack[i];
		stack[size->size_a - 1] = tmp[0];
		i = 0;
		while (++i < size->size_a)
			stack[i - 1] = tmp[i];
		free(tmp);
	}
}

void	rra(int *stack, t_size *size)
{
	reverse_ra(stack, size);
	write(1, "rra\n", 4);
}

void	reverse_rb(int *stack, t_size *size)
{
	int		*tmp;
	int		i;

	if (size->size_b > 1)
	{
		tmp = malloc(size->size_b * sizeof(int));
		i = -1;
		while (++i < size->size_b)
			tmp[i] = stack[i];
		stack[size->size_b - 1] = tmp[0];
		i = 0;
		while (++i < size->size_b)
			stack[i - 1] = tmp[i];
		free(tmp);
	}
}

void	rrb(int *stack, t_size *size)
{
	reverse_rb(stack, size);
	write(1, "rrb\n", 4);
}

void	rrr(int *stack_a, int *stack_b, t_size *size)
{
	reverse_ra(stack_a, size);
	reverse_rb(stack_b, size);
	write(1, "rrr\n", 4);
}
