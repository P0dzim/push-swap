/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:18:26 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/07 12:18:27 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_move(t_array *array)
{
	int	i;

	array->beggin = (array->beggin - 1) % array->len;
	if (array->beggin < 0)
		array->beggin = array->end;
	array->end = (array->end - 1) % array->len;
	if (array->end < 0)
		array->end = array->end + array->len;
	i = array->beggin;
	while (i != array->end)
	{
		array->stack[i].pos = i;
		i = (array->beggin + i + 1) % array->len;
	}
}

void	rra_move(t_array *array_a)
{
	ft_putstr_fd("rra\n", 1);
	reverse_move(array_a);
}

void	rrb_move(t_array *array_b)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_move(array_b);
}

void	rrr_move(t_array *array_a, t_array *array_b)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_move(array_a);
	reverse_move(array_b);
}
