/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_big_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:53:58 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:46 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	final_moves(t_container *container);

void	the_big_sort(t_container *cont_a, t_container *cont_b)
{
	while ((cont_a->total / 2) > cont_b->len && cont_a->len > 3)
	{
		if (cont_a->stack->target_pos > cont_a->total / 2)
			ra_move(cont_a);
		else
			pb_move(cont_a, cont_b);
	}
	while (cont_a->len > 3)
		pb_move(cont_a, cont_b);
	sort_three(cont_a);
	while (cont_b->len)
	{
		sign_cost(cont_a, cont_b);
		shortcut_way(cont_a, cont_b);
	}
	final_moves(cont_a);
}

static void	final_moves(t_container *container)
{
	t_stack	*node;
	size_t	i;

	node = container->stack;
	while (node->target_pos != 0)
		node = node->next;
	i = node->pos;
	while (!is_sorted(container) && i < container->len / 2)
		ra_move(container);
	while (!is_sorted(container) && i >= container->len / 2)
		reverse_a(container);
}
