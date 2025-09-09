/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:17:33 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 12:17:34 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_move(t_container *cont_in, t_container *cont_out)
{
	t_stack	*node;

	cont_in->len++;
	cont_out->len--;
	node = cont_out->stack;
	node->before->next = node->next;
	node->next->before = node->before;
	cont_out->stack = node->next;
	if (cont_in->stack != NULL)
	{
		node->before = cont_in->stack->before;
		node->next = cont_in->stack;
		cont_in->stack->before->next = node;
		cont_in->stack->before = node;
	}
	else
	{
		node->before = node;
		node->next = node;
		cont_in->stack = node;
	}
	update_pos(cont_in);
	update_pos(cont_out);
}

void	pa_move(t_container *contA, t_container *contB)
{
	ft_putstr_fd("pa\n", 1);
	push_move(contA, contB);
}

void	pb_move(t_container *contA, t_container *contB)
{
	ft_putstr_fd("pb\n", 1);
	push_move(contB, contA);
}
