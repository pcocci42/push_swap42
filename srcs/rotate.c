/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:22:35 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 10:22:49 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	rotate_a(int *stack, t_size *size)
{
	int		*tmp;
	int		i;

	if (size->size_a > 1)
	{
		tmp = malloc(size->size_a * sizeof(int));
		i = -1;
		while (++i < size->size_a)
			tmp[i] = stack[i];
		stack[0] = tmp[size->size_a - 1];
		i = 0;
		while (++i < size->size_a)
			stack[i] = tmp[i - 1];
		free(tmp);
	}
}

void	ra(int *stack, t_size *size)
{
	rotate_a(stack, size);
	write(1, "ra\n", 3);
}

void	rotate_b(int *stack, t_size *size)
{
	int	*tmp;
	int	i;

	if (size->size_b > 1)
	{
		tmp = malloc(size->size_b * sizeof(int));
		i = -1;
		while (++i < size->size_b)
			tmp[i] = stack[i];
		stack[0] = tmp[size->size_b -1];
		i = 0;
		while (++i < size->size_b)
			stack[i] = tmp[i - 1];
		free(tmp);
	}
}

void	rb(int *stack, t_size *size)
{
	rotate_b(stack, size);
	write(1, "rb\n", 3);
}

void	rotate_all(int *stack_a, int *stack_b, t_size *size)
{
	rotate_a(stack_a, size);
	rotate_b(stack_b, size);
	write(1, "rr\n", 3);
}
