/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:30:34 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/24 10:13:58 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/includes/libft.h"

void	done(int *stack_a, int *stack_b, t_size *size)
{
	free(stack_a);
	free(stack_b);
	free(size);
	exit(0);
}

int	check_sort(int *stack, int size)
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

void	sort(int *stack_a, int n)
{	
	int		*stack_b;
	t_size	*size;

	size = malloc(sizeof(t_size));
	size->size_a = n;
	stack_b = malloc(size->size_a * sizeof(int));
	size->size_b = 0;
	if (check_sort(stack_a, size->size_a))
		done(stack_a, stack_b, size);
	if (size->size_a == 4)
		pb(stack_a, stack_b, size);
	else if (size->size_a > 3)
	{
		pb(stack_a, stack_b, size);
		pb(stack_a, stack_b, size);
	}
	while (size->size_a > 3)
		sort_a(stack_a, stack_b, size);
	sort_3(stack_a, size);
	while (size->size_b != 0)
		sort_b(stack_a, stack_b, size);
	correct_a (stack_a, size);
	done(stack_a, stack_b, size);
}

int	main(int ac, char **av)
{
	int		*stack_a;
	int		n;
	int		i;
	int		size;

	n = ac -1;
	i = 0;
	if (ac > 2)
	{	
		if (check_many(av) == 1)
		{
			stack_a = malloc((sizeof(stack_a)) * (ac - 1));
			while (n > 0)
			{
				stack_a[i] = ft_atoi2(av[n]);
				n--;
				i++;
			}
			size = ac - 1;
			sort(stack_a, size);
		} 
	}
	if (ac == 2)
		parse(av[1]);
}
