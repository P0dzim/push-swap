/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:23:48 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 18:23:51 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_move(t_array *array)
{
	int	i;

	array->beggin = (array->beggin + 1) % array->len;
	array->end = (array->end + 1) % array->len;
	i = array->beggin;
	while (i != array->end)
	{
		array->stack[i].pos = i;
		i = (array->beggin + i + 1) % array->len;
	}
}

void	ra_move(t_array *array_a)
{
	ft_putstr_fd("ra\n", 1);
	rotate_move(array_a);
}

void	rb_move(t_array *array_b)
{
	ft_putstr_fd("rb\n", 1);
	rotate_move(array_b);
}

void	rr_move(t_array *array_a, t_array *array_b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_move(array_a);
	rotate_move(array_b);
}
