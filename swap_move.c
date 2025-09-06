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

static void	swap_move(t_stack *stack)
{
	int	temp;

	temp = stack[0].value;
	stack[0].value = stack[1].value;
	stack[1].value = temp;
	temp = stack[0].pos;
	stack[0].pos = stack[1].pos;
	stack[1].pos = temp;
}

void	sa_move(t_stack *stack_a)
{
	ft_putstr_fd("sa\n", 1);
	swap_move(stack_a);
}

void	sb_move(t_stack *stack_a)
{
	ft_putstr_fd("sb\n", 1);
	swap_move(stack_a);
}

void	ss_move(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_move(stack_a);
	swap_move(stack_b);
}
