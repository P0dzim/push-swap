/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:11:01 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 18:11:03 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	higher_top(t_array *array);
static void	higher_mid(t_array *array);

void	sort_three(t_array *array)
{
	int		value[3];
	t_stack	*stack;

	stack = array->stack;
	value[0] = stack[array->beggin].value;
	value[1] = stack[array->beggin + 1].value;
	value[2] = stack[array->beggin + 2].value;
	if (value[0] > value[1] && value[0] > value[2])
		higher_top(array);
	else if (value[1] > value[2] && value[1] > value[0])
		higher_mid(array);
	else
		sa_move(array);
}

static void	higher_top(t_array *array)
{
	ra_move(array);
	if (its_sorted(array))
		return ;
	sa_move(array);
}

static void	higher_mid(t_array *array)
{
	rra_move(array);
	if (its_sorted(array))
		return ;
	sa_move(array);
}
