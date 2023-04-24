/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:39:45 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:48:16 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

void	ft_exit(t_stack	*stack, char **split, char *str)
{
	bonus_free_split(split, str);
	free_bonus(stack);
	exit(1);
}

int	bonus_check_sort(int *stack, int size)
{
	int	i;

	i = 0;
	while (++i < size)
	{
		if (stack[i] > stack[i - 1])
			return (0);
	}
	return (1);
}

void	ft_end(t_stack	*stack)
{
	if (bonus_check_sort(stack->stack, stack->size) == 1)
	{
		write(1, "OK\n", 4);
		free_all(stack);
	}
	else
	{
		write(1, "KO\n", 3);
		free_all(stack);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (ac == 1)
	{
		free(stack);
		exit(1);
	}
	if (ac > 2)
	{
		bonus_check_many(av, stack);
		fill_stack(stack, ac -1, av);
	}
	if (ac == 2)
	{
		fill_split(av[1], stack);
		if (stack->size <= 1)
		{
			free(stack);
			exit(1);
		}
	}
	read_op(stack);
}
