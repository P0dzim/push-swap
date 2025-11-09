/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:06:27 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:31 by vitosant         ###   ########.fr       */
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
	ft_putstr_fd("ra\n", 1);
	rotate_move(cont);
}

void	rb_move(t_container *cont)
{
	ft_putstr_fd("rb\n", 1);
	rotate_move(cont);
}

void	rr_move(t_container *cont_a, t_container *cont_b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_move(cont_a);
	rotate_move(cont_b);
}
