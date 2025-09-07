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

int	its_sorted(t_array *array)
{
	int	i;

	i = array->beggin;
	while (i != array->end)
	{
		if (array->stack[i].target_pos != (i - array->beggin) % array->len)
			return (0);
		i = (i + 1) % array->len;
	}
	return (1);
}
