/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:32:24 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:26:07 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	bonus_fz_isdigit(int x)
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

int	bonus_check_int(char *str)
{
	long int	val;

	val = long_atoi(str);
	if (val > INT_MAX || val < INT_MIN)
		return (0);
	return (1);
}

int	bonus_check_arg(char *str)
{
	int		i;
	int		sign_count;
	int		digit_count;

	i = 0;
	sign_count = 0;
	digit_count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign_count++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (!bonus_fz_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] == '+' || str[i] == '-')
			sign_count++;
		else
			digit_count++;
		i++;
	}
	if (digit_count == 0 || sign_count > 1)
		return (0);
	return (1);
}

int	bonus_check_many(char **av, t_stack *stack)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (bonus_check_arg(av[i]) != 1 || bonus_check_int(av[i]) != 1)
		{
			write(1, "Error\n", 7);
			free(stack);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	bonus_check_many2(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (bonus_check_arg(av[i]) != 1 || bonus_check_int(av[i]) != 1)
		{
			write(1, "Error\n", 7);
			return (0);
		}
		i++;
	}
	return (1);
}
