/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:10:27 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/26 10:46:58 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

long int	ft_atoi2(const char *str)
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

void	free_memory(char **split, char *str)
{
	int	i;

	i = 0;
	while (i < count_words(str, ' '))
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	*create_stack(int *stack_a, int i, int n, char **av)
{
	while (n > 0)
	{
		stack_a[i] = ft_atoi2(av[n]);
		n--;
		i++;
	}
	return (stack_a);
}

int	check_dup(int *stack_a, int size)
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

void	first_check_parse(char **split, char *str, int *stack_a)
{
	if (check_many2(split) != 1)
	{	
		free_memory(split, str);
		free(stack_a);
		exit(1);
	}
}
