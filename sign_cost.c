/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sign_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:17:21 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/10 12:17:23 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static ssize_t	first_half(t_container *cont, ssize_t target, ssize_t op);
static ssize_t	end_half(t_container *cont, ssize_t target, ssize_t op);
static ssize_t cost_calculation(t_container *cont, size_t target, ssize_t op);


void	sing_cost(t_container *contA, t_container *contB)
{
	size_t	i;
	t_stack	*node;

	i = 0;
	node = contB->stack;
	while (i < contB->len)
	{
		node->costB = cost_calculation(contB, node->target_pos - 1, 1);
		node->costA = cost_calculation(contA, node->target_pos, 1);
		node = node->next;
		i++;
	}
}

static ssize_t cost_calculation(t_container *cont, size_t target, ssize_t op)
{
	ssize_t	i;
	ssize_t	j;

	i = first_half(cont, target, op);
	j = end_half(cont, target, op);

	if (positive_num(i) > positive_num(j))
		return (j);
	return (i);
}

static ssize_t	first_half(t_container *cont, ssize_t target, ssize_t op)
{
	ssize_t	i;
	t_stack	*node;

	i =	(ssize_t)cont->len / 2;
	node = cont->stack;
	while (i)
	{
		if ((ssize_t)node->target_pos == target + op)
			return (node->pos);
		node = node->next;
		i--;
	}
	return (INT_EXPLOSION);
}

static ssize_t	end_half(t_container *cont, ssize_t target, ssize_t op)
{
	ssize_t		i;
	t_stack	*node;

	i =	0;
	node = cont->stack->before;
	while (i < (ssize_t)(cont->len / 2 + cont->len % 2))
	{
		if ((ssize_t)node->target_pos == target + op)
			return ((i * -1) - 1);
		node = node->before;
		i++;
	}
	return (INT_EXPLOSION);
}

size_t	positive_num(ssize_t nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
