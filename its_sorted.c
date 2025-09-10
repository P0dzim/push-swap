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

static int complete_conteiner(t_container *cont);

int	its_sorted(t_container *cont)
{
	size_t	i;
	t_stack	*node;

	i = 1;
	if (cont->len == cont->total)
		return (complete_conteiner(cont));
	node = cont->stack;
	while (i < cont->len)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

static int complete_conteiner(t_container *cont)
{
	size_t	i;
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