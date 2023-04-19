/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:31:20 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/19 14:31:05 by pcocci           ###   ########.fr       */
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
				write(1, "Duplicates\n", 12);
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

void    free_bonus(t_stack *stack, char **split, char *str)
{
    if (bonus_check_dup(stack->stack, stack->size) == 0)
    {
        bonus_free_split(split, str);
        free(stack->stack);
        free(stack);
    }
    else
        bonus_free_split(split, str);
}

void    fill_split(char *str, t_stack *stack)
{   
    char    **split;
    int     i;
    int     n;

    n = 0;
    i = bonus_count_words(str, ' ') - 1;
    stack->size = bonus_count_words(str, ' ');
    stack->stack = malloc(sizeof(int) * stack->size);
    split = bonus_split(str, ' ');
    if (bonus_check_many2(split) == 0)
    {
        bonus_free_split(split, str);
        free(stack->stack);
        free(stack);
        exit(1);
    }
    while (n < bonus_count_words(str, ' '))
	{
		stack->stack[n]= long_atoi(split[i]);
		n++;
		i--;
	}
    free_bonus(stack, split, str);
}

