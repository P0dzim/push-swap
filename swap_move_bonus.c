/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:29:06 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/13 20:42:39 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap_move(t_container *cont)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!cont->stack)
		return ;
	if (cont->len < 3)
		cont->stack = cont->stack->next;
	if (cont->len < 3)
		return ;
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

void	s_operation(t_container *cont_a, t_container *cont_b, int i)
{
	if (i == 0)
		swap_move(cont_a);
	else if (i == 1)
		swap_move(cont_b);
	else
	{
		swap_move(cont_a);
		swap_move(cont_b);
	}
}
