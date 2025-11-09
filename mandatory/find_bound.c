/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bound.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:07:36 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:08 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	find_lower_bound(t_container *cont, size_t target)
{
	ssize_t	i;
	t_stack	*node;
	t_stack	*lower;

	i = 0;
	node = cont->stack;
	lower = NULL;
	while (i < (ssize_t)cont->len)
	{
		if (node->target_pos < target
			&& (!lower || lower->target_pos > node->target_pos))
			lower = node;
		node = node->next;
		i++;
	}
	i = (ssize_t)lower->pos;
	if (i > (ssize_t)cont->len / 2)
		i = (ssize_t)cont->len * -1 + i;
	return (i);
}

ssize_t	find_upper_bound(t_container *cont, size_t target)
{
	ssize_t	i;
	t_stack	*node;
	t_stack	*upper;

	i = 0;
	node = cont->stack;
	upper = NULL;
	while (i < (ssize_t)cont->len)
	{
		if (node->target_pos > target
			&& (!upper || upper->target_pos > node->target_pos))
			upper = node;
		node = node->next;
		i++;
	}
	if (upper == NULL)
		return (find_lower_bound(cont, target));
	i = (ssize_t)upper->pos;
	if (i > (ssize_t)cont->len / 2)
		i = (ssize_t)cont->len * -1 + i;
	return (i);
}
