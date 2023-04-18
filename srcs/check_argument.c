/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:52:03 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/18 10:48:01 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"
#include <limits.h>

int	fz_isdigit(int x)
{
	if (x >= 48 && x <= 57)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int check_int(char *str)
{
	long int val;
    val = ft_atoi2(str);
	
    if (val > INT_MAX || val < INT_MIN)
        return (0);
    return (1);
}

int check_arg(char *str)
{
    int i = 0;
    int sign_count = 0;
    int digit_count = 0;
    char c;
    if (str[i] == '+' || str[i] == '-')
	{
        sign_count++;
        i++;
    }
    while (str[i] != '\0') 
	{
        c = str[i];
        if (!fz_isdigit(c) && c != '+' && c != '-')
        	return (0);
        if (c == '+' || c == '-')
            sign_count++;
        else
            digit_count++;
        i++;
    }
    if (digit_count == 0 || sign_count > 1)
        return (0);
    return (1);
}

int	check_many(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (check_arg(av[i]) != 1 || check_int(av[i]) != 1)
		{
			write(1, "Error\n", 7);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	check_many2(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (check_arg(av[i]) != 1 || check_int(av[i]) != 1)
		{
			write(1, "Error\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_dup(int *stack_a, int size)
{	
	int i;
	int j;

	i = 1;
	while (i < size)
	{	
		j = 0;
		while (j < size)
		{
			if (stack_a[i] == stack_a[j] && i != j)
			{
				write(1, "Duplicates\n", 12);
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}