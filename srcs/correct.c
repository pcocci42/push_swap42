/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:29:37 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 10:29:38 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	correct_a(int *stack_a, t_size *size)
{
	int	index;

	index = min(stack_a, size->size_a);
	if (index != size->size_a - 1)
	{
		if (index >= size->size_a / 2)
		{
			while (index < size->size_a - 1)
			{
				ra(stack_a, size);
				index++;
			}
		}
	}
	if (index < size->size_a / 2)
	{
		while (index >= 0)
		{
			rra(stack_a, size);
			index--;
		}
	}
}
