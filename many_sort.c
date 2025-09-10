/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:53:58 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 14:54:00 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static void	final_moves(t_container *container);

void	many_sort(t_container *contA, t_container *contB)
{
	while ((contA->total / 2) > contB->len && contA->len > 3)
	{
		if (contA->stack->target_pos > contA->total / 2)
			ra_move(contA);
		else
			pb_move(contA, contB);
	}
	while (contA->len > 3)
		pb_move(contA, contB);
	sort_three(contA);
	while(contB->len)
	{
		sing_cost(contA, contB);
		shortcut_way(contA, contB);
	}
		// #include <stdio.h>
		// t_stack *node2 = contA->stack;
		// for (size_t i = 0; i < contA->len; i++)
		// {
		// 	printf("value: %i, target_pos: %zu, pos: %zu\n", node2->value, node2->target_pos, node2->pos);
		// 	node2 = node2->next;
		// }
		// node2 = contB->stack;
		// printf("\n---------LISTA B------------\n");
		// for (size_t j = 0; j < contB->len; j++)
		// {
		// 	ft_printf("value: %i, pos: %i,  target_pos: %i, costA: %i, costB: %i\n", node2->value, node2->pos, node2->target_pos, node2->costA, node2->costB);
		// 	node2 = node2->next;
		// }
	//final_moves(contA);
}

// static void	final_moves(t_container *container)
// {
// 	t_stack	*node;
// 	size_t	i;

// 	node = container->stack;
// 	while (node->target_pos != 0)
// 		node = node->next;
// 	i = node->pos;
// 	while (!its_sorted(container) && i < container->len / 2)
// 		ra_move(container);
// 	while (!its_sorted(container) && i >= container->len / 2)
// 		reverse_a(container);
// }
