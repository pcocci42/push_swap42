/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:35:11 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 10:38:45 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	cases(int *stack_a, int top, int mid, t_size *size)
{
	int	bot;

	bot = (stack_a[0] > stack_a[2]);
	if (top && !mid && bot)
		sa(stack_a, size);
	if (top && mid && !bot)
	{
		sa(stack_a, size);
		rra(stack_a, size);
	}
	if (top && !mid && !bot)
		ra(stack_a, size);
	if (!top && mid && bot)
	{
		sa(stack_a, size);
		ra(stack_a, size);
	}
	if (!top && mid && !bot)
		rra(stack_a, size);
}

void	sort_3(int *stack_a, t_size *size)
{
	int	top;
	int	mid;

	top = (stack_a[2] > stack_a[1]);
	mid = (stack_a[1] > stack_a[0]);
	cases(stack_a, top, mid, size);
}
