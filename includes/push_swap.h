/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:40:46 by pcocci            #+#    #+#             */
/*   Updated: 2023/02/24 10:31:04 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct size
{
	int	size_a;
	int	size_b;
}	t_size;

typedef struct s_operations
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_operations;

void	swap_a(int *stack, t_size *size);
void	sa(int *stack, t_size *size);
void	swap_b(int *stack, t_size *size);
void	sb(int *stack, t_size *size);
void	swap_all(int *stack_a, int *stack_b, t_size *size);
void	push_b(int *stack_a, int *stack_b, t_size *size);
void	push_a(int *stack_a, int *stack_b, t_size *size);
void	pa(int *stack_a, int *stack_b, t_size *size);
void	pb(int *stack_a, int *stack_b, t_size *size);
void	rotate_a(int *stack, t_size *size);
void	ra(int *stack, t_size *size);
void	rotate_b(int *stack, t_size *size);
void	rb(int *stack, t_size *size);
void	rotate_all(int *stack_a, int *stack_b, t_size *size);
void	reverse_ra(int *stack, t_size *size);
void	rra(int *stack, t_size *size);
void	reverse_rb(int *stack, t_size *size);
void	rrb(int *stack, t_size *size);
void	rrr(int *stack_a, int *stack_b, t_size *size);
void	swap(int *a, int *b);
void	sort_3(int *stack_a, t_size *size);
void	cases(int *stack_a, int top, int mid, t_size *size);
void	correct_a(int *stack_a, t_size *size);
void	print_stacks(int *stack_a, int *stack_b, t_size *size);
void	count_r(int index, int size, t_operations *op, int a);
void	fuck_bzero(void *s, int n);
void	sort_a(int *stack_a, int *stack_b, t_size *size);
void	sort_b(int *stack_a, int *stack_b, t_size *size);
int		min(int *stack, int size);
void	less_op(t_operations *op);
int		diff(t_operations min, t_operations op);
void	parse(char *str);
int		ft_atoi2(const char *str);
int		count_words(const char *str, char c);
void	sort(int *stack_a, int n);
size_t	ft_strlen2(const char *str);
int		check_many(char **av);
int		check_many2(char **av);

#endif