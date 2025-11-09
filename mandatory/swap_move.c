/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:29:06 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:44 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_move(t_container *cont)
{
	t_stack	*node1;
	t_stack	*node2;

	node1 = cont->stack;
	node2 = cont->stack->next;
	node1->before->next = node2;
	node2->next->before = node1;
	node2->before = node1->before;
	node1->before = node2;
	node1->next = node2->next;
	node2->next = node1;
	cont->stack = node2;
	update_pos(cont);
}

void	sa_move(t_container *cont)
{
	ft_putstr_fd("sa\n", 1);
	swap_move(cont);
}

void	sb_move(t_container *cont)
{
	ft_putstr_fd("sb\n", 1);
	swap_move(cont);
}

void	ss_move(t_container *cont_a, t_container *cont_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_move(cont_a);
	swap_move(cont_b);
}
