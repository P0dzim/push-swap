/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   its_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:31:32 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 16:31:34 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	its_sorted(t_stack *stack, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (stack[i].target_pos != i)
			return (0);
		i++;
	}
	return (1);
}
