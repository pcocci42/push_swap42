/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:33:56 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/20 13:47:56 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	count_r(int index, int size, t_operations *op, int a)
{
	if (index < size / 2)
	{
		if (a)
			op->rra = index + 1;
		else
			op->rrb = index + 1;
	}
	else
	{
		if (a)
			op->ra = size - index - 1;
		else
			op->rb = size - index - 1;
	}
}

int	diff(t_operations min, t_operations op)
{
	int	n1;
	int	n2;

	n1 = min.ra + min.rb + min.rr + min.rra + min.rrb + min.rrr;
	n2 = op.ra + op.rb + op.rr + op.rra + op.rrb + op.rrr;
	return (n2 < n1);
}

void	less_op(t_operations *op)
{
	int	min_r;
	int	min_rr;

	if (op->ra < op->rb)
		min_r = op->ra;
	else
		min_r = op->rb;
	if (op->rra < op->rrb)
		min_rr = op->rra;
	else
		min_rr = op->rrb;
	op->ra -= min_r;
	op->rb -= min_r;
	op->rr = min_r;
	op->rra -= min_rr;
	op->rrb -= min_rr;
	op->rrr = min_rr;
}

void	fuck_bzero(void *s, int n)
{
	char	*str;
	int		i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
