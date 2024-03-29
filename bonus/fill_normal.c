/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:05:32 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:41:26 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

void	fill_stack(t_stack *stack, int size, char **av)
{
	int	i;
	int	n;

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

int	check_in(char *str)
{
	int	flag;

	flag = 0;
	if (ft_strncmp(str, "pb\n", 3) == 0
		|| ft_strncmp(str, "pa\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "ra\n", 3) == 0
		|| ft_strncmp(str, "rb\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rra\n", 4) == 0
		|| ft_strncmp(str, "rrb\n", 4) == 0)
		flag = 1;
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		flag = 1;
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		flag = 1;
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		flag = 1;
	return (flag);
}

void	free_all(t_stack *stack)
{
	free(stack->stack);
	free(stack->stack_b);
	free(stack->t_size);
	free(stack);
}

void	allocate_size(t_stack *stack)
{
	stack->t_size = malloc(sizeof(t_size));
	stack->t_size->size_a = stack->size;
	stack->t_size->size_b = 0;
}

void	read_op(t_stack *stack)
{
	char	*str;

	if (stack->size > 1)
	{
		stack->stack_b = malloc((sizeof(int)) * (stack->size));
		allocate_size(stack);
		while (1)
		{
			str = get_next_line(0);
			if (str == NULL)
				break ;
			else if (check_in(str) == 0)
				ft_wrong_rl(stack, str);
			else
			{
				do_op(stack, str);
				free(str);
			}
		}
		ft_end(stack);
	}
}
