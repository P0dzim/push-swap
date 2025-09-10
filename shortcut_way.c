/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:32:24 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 16:32:25 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ca_moves(t_container *contA, t_stack *node);
static void	cb_moves(t_container *contB, t_stack *node);
static void	exploxion(t_container *contA, t_container *contB);

void	shortcut_way(t_container *contA, t_container *contB)
{
	t_stack	*node[2];
	size_t	i;

	node[0] = contB->stack;
	node[1] = node[0];
	i = 0;
	while (i < contB->len)
	{
		if (positive_num(node[0]->costA) + positive_num(node[0]->costB)
			< positive_num(node[1]->costA) + positive_num(node[1]->costB))
			node[1] = node[0];
		node[0] = node[0]->next;
		i++;
	}
	if (node[1]->costA == INT_EXPLOSION)
	{
		exploxion(contA, contB);
		shortcut_way(contA, contB);
		return ;
	}
	ca_moves(contA, node[1]);
	cb_moves(contB, node[1]);
	pa_move(contA, contB);
}

static void	ca_moves(t_container *contA, t_stack *node)
{
	while (node->costA)
	{
		if (node->costA > 0)
		{
			ra_move(contA);
			node->costA--;
		}
		if (node->costA < 0)
		{
			reverse_a(contA);
			node->costA++;
		}
	}
}

static void	cb_moves(t_container *contB, t_stack *node)
{
	while (node->costB)
	{
		if (node->costB > 0)
		{
			rb_move(contB);
			node->costB--;
		}
		if (node->costB < 0)
		{
			reverse_b(contB);
			node->costB++;
		}
	}
}

static void	exploxion(t_container *contA, t_container *contB)
{
	t_stack	*node[2];

	node[B] = contB->stack;
	while (node[B]->target_pos != contA->total - 1)
		node[B] = node[B]->next;
	node[A] = contA->stack;
	while (node[A]->target_pos != 0)
		node[A] = node[A]->next;
	node[B]->costA = node[A]->pos;
	if (node[A]->pos > contA->len / 2)
		node[B]->costA = -(contA->len / 2) + node[B]->costA;
}
