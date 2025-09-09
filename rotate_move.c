/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:06:27 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 12:06:27 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_move(t_container *cont)
{
	cont->stack = cont->stack->next;
	update_pos(cont);
}

void	ra_move(t_container *cont)
{
	ft_putstr_fd( "ra\n", 1);
	rotate_move(cont);
}

void	rb_move(t_container *cont)
{
	ft_putstr_fd( "rb\n", 1);
	rotate_move(cont);
}

void	rr_move(t_container *contA, t_container *contB)
{
	ft_putstr_fd( "rr\n", 1);
	rotate_move(contA);
	rotate_move(contB);
}