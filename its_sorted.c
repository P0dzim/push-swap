/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:43:22 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 12:43:24 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	its_sorted(t_container *cont)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = cont->stack;
	while (i < cont->len)
	{
		if (node->pos != node->target_pos)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}
