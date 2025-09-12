/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:17:21 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:38 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sign_cost(t_container *cont_a, t_container *cont_b)
{
	size_t	i;
	t_stack	*node;

	i = 0;
	node = cont_b->stack;
	while (i < cont_b->len)
	{
		node->cost_b = node->pos;
		if (node->pos > cont_b->len / 2)
			node->cost_b = (ssize_t)cont_b->len * -1 + node->cost_b;
		node->cost_a = find_upper_bound(cont_a, node->target_pos);
		node = node->next;
		i++;
	}
}

size_t	positive_num(ssize_t nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
