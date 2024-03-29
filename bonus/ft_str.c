/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paolococci <paolococci@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:38:40 by pcocci            #+#    #+#             */
/*   Updated: 2023/04/24 11:41:39 by paolococci       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] > s2[i])
		{
			if (s1[i] == '\0')
			{
				return (-(s1[i] - s2[i]));
			}
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			if (s2[i] == '\0')
			{
				return (-(s1[i] - s2[i]));
			}
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
