/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 17:27:41 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 17:27:42 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_move(t_array *array)
{
	t_stack	temp;

	temp = array->stack[array->beggin];
	array->stack[array->beggin] = array->stack[array->beggin + 1];
	array->stack[array->beggin + 1] = temp;
	array->stack[array->beggin].pos--;
	array->stack[array->beggin + 1].pos++;
	// array->stack[array->beggin].value = array->stack[array->beggin + 1].value;
	// array->stack[array->beggin + 1].value = temp;
	// temp = array->stack[array->beggin].pos;
	// array->stack[array->beggin].pos = array->stack[array->beggin + 1].pos;
	// array->stack[array->beggin + 1].pos = temp;
}

void	sa_move(t_array *array_a)
{
	ft_putstr_fd("sa\n", 1);
	swap_move(array_a);
}

void	sb_move(t_array *array_b)
{
	ft_putstr_fd("sb\n", 1);
	swap_move(array_b);
}

void	ss_move(t_array *array_a, t_array *array_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_move(array_a);
	swap_move(array_b);
}
