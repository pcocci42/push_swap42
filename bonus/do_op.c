/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:43:28 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/19 14:21:57 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

void	bonus_rrr(int *stack_a, int *stack_b, t_size *size)
{
	reverse_ra(stack_a, size);
	reverse_rb(stack_b, size);
}
void    do_op(t_stack *stack, char *str)
{
    if (ft_strncmp(str, "pb\n", 3) == 0)
        push_b(stack->stack, stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "pa\n", 3) == 0)
        push_a(stack->stack, stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
        rotate_a(stack->stack, stack->t_size);
	else if(ft_strncmp(str, "rb\n", 3) == 0)
		rotate_b(stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rotate_all(stack->stack, stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
        reverse_ra(stack->stack, stack->t_size);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
        reverse_rb(stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		bonus_rrr(stack->stack, stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		swap_a(stack->stack, stack->t_size);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap_b(stack->stack_b, stack->t_size);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
        swap_all(stack->stack, stack->stack_b, stack->t_size);
}