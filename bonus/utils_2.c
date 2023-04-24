/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:39:45 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:39:57 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

void	ft_wrong_rl(t_stack *stack, char *str)
{
	write(2, "Error\n", 7);
	free_all(stack);
	free(str);
	exit(0);
}
