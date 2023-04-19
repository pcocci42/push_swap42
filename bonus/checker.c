/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:39:45 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/19 13:18:17 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include "bonus.h"

int main(int ac, char **av)
{
    t_stack *stack;

    if (ac == 1)
        exit(1);
    stack = malloc(sizeof(t_stack));
    if (ac > 2)
    {   
        bonus_check_many(av, stack);
        fill_stack(stack, ac - 1, av);
    }
    if (ac == 2)
    {
        fill_split(av[1], stack);
    }
}