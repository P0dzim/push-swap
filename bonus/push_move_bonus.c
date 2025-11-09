/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:17:33 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 14:35:45 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push_move(t_container *cont_in, t_container *cont_out)
{
	t_stack	*node;

	cont_in->len++;
	cont_out->len--;
	node = cont_out->stack;
	node->before->next = node->next;
	node->next->before = node->before;
	cont_out->stack = node->next;
	if (cont_in->stack == NULL)
	{
		node->before = node;
		node->next = node;
	}
	add_node(cont_in, node);
	if (cont_out->len == 0)
		cont_out->stack = NULL;
	cont_in->stack = cont_in->stack->before;
	update_pos(cont_in);
	update_pos(cont_out);
}

void	p_operation(t_container *cont_a, t_container *cont_b, int i)
{
	if ((i == 10 && !cont_a->stack) || (i == 9 && !cont_b->stack))
		return ;
	if (i == 9)
		push_move(cont_a, cont_b);
	else
		push_move(cont_b, cont_a);
}
