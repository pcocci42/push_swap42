/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcocci <pcocci@student.42firenze.it>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:33:47 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/19 13:15:21 by pcocci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
    int *stack;
    int size;
} t_stack;

int         check_int(char *str);
long int	long_atoi(const char *str);
int	        check_many2(char **av);
int	        bonus_check_many(char **av, t_stack *stack);
char	    **bonus_split(char const *s, char c);
char	    *bonus_word_dup(const char *str, int start, int finish);
void        fill_split(char *str, t_stack *stack);
int         bonus_count_words(const char *str, char c);
int         bonus_check_dup(int *stack_a, int size);
void        bonus_free_split(char **split, char *str);
void        free_bonus(t_stack *stack, char **av, char *str);
void        fill_stack(t_stack *stack, int size, char **av);

#endif