/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:43:22 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 15:33:49 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_container *cont)
{
	size_t	i;
	t_stack	*node;

	i = 0;
	node = cont->stack;
	if (cont->len != cont->total)
		return (0);
	while (i < cont->len)
	{
		if (node->pos != node->target_pos)
			return (0);
		i++;
		node = node->next;
	}
	return (1);
}
