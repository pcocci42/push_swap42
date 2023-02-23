/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:52:03 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/23 15:30:44 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

int check_many(char **av)
{	
	int i;
	int n;

	i = 1;
	while (av[i])
	{
		n = 0;
		if ((ft_atoi2(av[i]) > 2147483647) || (ft_atoi2(av[i]) < -2147483646))
			return (-1);
		if (av[i][n] > '9' || av[i][n] < '0')
			return (-1);
		i++;
		n++;
	}	
	return (0);
}