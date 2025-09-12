/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortcut_way.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 16:32:24 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:36 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ca_moves(t_container *cont_a, t_stack *node);
static void	cb_moves(t_container *cont_b, t_stack *node);
static void	one_way(t_container *cont_a, t_container *cont_b, t_stack *node);

void	shortcut_way(t_container *cont_a, t_container *cont_b)
{
	t_stack	*node[2];
	size_t	i;

	node[0] = cont_b->stack;
	node[1] = node[0];
	i = 0;
	while (i < cont_b->len)
	{
		if (positive_num(node[0]->cost_a) + positive_num(node[0]->cost_b)
			< positive_num(node[1]->cost_a) + positive_num(node[1]->cost_b))
			node[1] = node[0];
		node[0] = node[0]->next;
		i++;
	}
	if ((node[1]->cost_a > 0 && node[1]->cost_b > 0)
		|| (node[1]->cost_a < 0 && node[1]->cost_b < 0))
		one_way(cont_a, cont_b, node[1]);
	ca_moves(cont_a, node[1]);
	cb_moves(cont_b, node[1]);
	pa_move(cont_a, cont_b);
}

static void	ca_moves(t_container *cont_a, t_stack *node)
{
	while (node->cost_a)
	{
		if (node->cost_a > 0)
		{
			ra_move(cont_a);
			node->cost_a--;
		}
		if (node->cost_a < 0)
		{
			reverse_a(cont_a);
			node->cost_a++;
		}
	}
}

static void	cb_moves(t_container *cont_b, t_stack *node)
{
	while (node->cost_b)
	{
		if (node->cost_b > 0)
		{
			rb_move(cont_b);
			node->cost_b--;
		}
		if (node->cost_b < 0)
		{
			reverse_b(cont_b);
			node->cost_b++;
		}
	}
}

static void	one_way(t_container *cont_a, t_container *cont_b, t_stack *node)
{
	while (node->cost_a && node->cost_b)
	{
		if (node->cost_a > 0 && node->cost_b > 0)
		{
			rr_move(cont_a, cont_b);
			node->cost_a--;
			node->cost_b--;
		}
		if (node->cost_a < 0 && node->cost_b < 0)
		{
			reverse_r(cont_a, cont_b);
			node->cost_a++;
			node->cost_b++;
		}
	}
}
