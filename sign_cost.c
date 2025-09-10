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

static t_stack	*first_half(t_container *cont, ssize_t target, ssize_t op);
static t_stack	*end_half(t_container *cont, ssize_t target, ssize_t op);
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
	t_stack	*i;
	t_stack	*j;
	ssize_t	len;

	i = first_half(cont, target, op);
	j = end_half(cont, target, op);
	len = (ssize_t)cont->len;
	if (i->target_pos == target + op || j->target_pos < target + op)
		return (i->pos);
	else if (j->target_pos == target + op || i->target_pos < target + op)
		return (-len + (ssize_t)j->pos);
	else if (positive_num(i->pos) > positive_num(-len + (ssize_t)j->pos))
		return (-len + (ssize_t)j->pos);
	else
		return (i->pos);
}

static t_stack	*first_half(t_container *cont, ssize_t target, ssize_t op)
{
	ssize_t	i;
	t_stack	*node;
	t_stack	*near;

	i =	(ssize_t)cont->len / 2;
	node = cont->stack;
	near = cont->stack;
	while (i)
	{
		if ((ssize_t)node->target_pos == target + op)
			return (node);
		if (node != cont->stack && target < (ssize_t)node->target_pos
			&& near->pos > node->pos)
			near = node;
		node = node->next;
		i--;
	}
	return (near);
}

static t_stack	*end_half(t_container *cont, ssize_t target, ssize_t op)
{
	ssize_t		i;
	t_stack	*node;
	t_stack	*near;

	i =	0;
	node = cont->stack->before;
	near = node;
	while (i < (ssize_t)(cont->len / 2 + cont->len % 2))
	{
		if ((ssize_t)node->target_pos == target + op)
			return (node);
		if (node != cont->stack && target < (ssize_t)node->target_pos
			&& near->pos < node->pos)
			near = node;
		node = node->before;
		i++;
	}
	return (near);
}

size_t	positive_num(ssize_t nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
