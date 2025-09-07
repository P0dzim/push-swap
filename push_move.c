/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 12:30:18 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/07 12:30:19 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_move(t_array *array_a, t_array *array_b)
{
	int	i;

	i = array_a->beggin - 1;
	if (array_b->len == 0 || i < 0)
		return ;
	array_a->stack[i] = array_b->stack[array_b->beggin];
	array_a->len++;
	array_b->len--;
	array_b->beggin = (array_b->beggin + 1) % array_b->len;
	array_a->beggin = i;
}

void	pa_move(t_array *array_a, t_array *array_b)
{
	ft_putstr_fd("pa\n", 1);
	push_move(array_a, array_b);
}

void	pb_move(t_array *array_a, t_array *array_b)
{
	ft_putstr_fd("pb\n", 1);
	push_move(array_b, array_a);
}
