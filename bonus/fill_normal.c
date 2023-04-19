/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:05:32 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/19 13:16:07 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "bonus.h"

void    fill_stack(t_stack *stack, int size, char **av)
{   
    int i;
    int n;

    i = 0;
    n = size;
    stack->size = size;
    stack->stack = malloc((sizeof(int)) * (size));
    while (n > 0)
	{
		stack->stack[i] = long_atoi(av[n]);
		n--;
		i++;
	}
    if (bonus_check_dup(stack->stack, size) == 0)
    {
        free(stack->stack);
        free(stack);
        exit(1);
    }
}