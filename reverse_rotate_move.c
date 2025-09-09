/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:12:59 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 12:13:00 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_move(t_container *cont)
{
	cont->stack = cont->stack->before;
	update_pos(cont);
}

void	reverse_a(t_container *cont)
{
	ft_putstr_fd("rra\n", 1);
	reverse_move(cont);
}

void	reverse_b(t_container *cont)
{
	ft_putstr_fd("rrb\n", 1);
	reverse_move(cont);
}

void	reverse_r(t_container *contA, t_container *contB)
{
	ft_putstr_fd("rrr\n", 1);
	reverse_move(contA);
	reverse_move(contB);
}
