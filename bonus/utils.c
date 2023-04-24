/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:31:20 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:33:13 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

long int	long_atoi(const char *str)
{
	long int	sign;
	long int	result;
	int			i;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	result *= sign;
	return (result);
}

int	bonus_check_dup(int *stack_a, int size)
{	
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{	
		j = 0;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j] && i != j)
			{
				write(1, "Error\n", 7);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	bonus_free_split(char **split, char *str)
{
	int	i;

	i = 0;
	while (i < bonus_count_words(str, ' '))
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_bonus(t_stack *stack)
{
	free(stack->stack);
	free(stack);
}

void	fill_split(char *str, t_stack *stack)
{
	char	**split;
	int		i;
	int		n;

	n = 0;
	i = bonus_count_words(str, ' ') - 1;
	stack->size = bonus_count_words(str, ' ');
	if (stack->size > 1)
	{
		split = bonus_split(str, ' ');
		stack->stack = malloc(sizeof(int) * stack->size);
		while (n < bonus_count_words(str, ' '))
		{
			stack->stack[n] = long_atoi(split[i]);
			n++;
			i--;
		}
		if (bonus_check_many2(split) == 0
			|| bonus_check_dup(stack->stack, stack->size) == 0)
			ft_exit(stack, split, str);
		bonus_free_split(split, str);
	}
}
