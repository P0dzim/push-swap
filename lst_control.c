/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:32:34 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:14 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_node(t_array item);

void	fill_lst(t_array *array, t_container *container)
{
	size_t	i;
	t_stack	*node;

	i = 0;
	while (i < container->len)
	{
		node = create_node(array[i]);
		if (node)
			add_node(container, node);
		i++;
	}
}

static t_stack	*create_node(t_array item)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = item.value;
	node->target_pos = item.target_pos;
	node->pos = item.pos;
	node->before = node;
	node->next = node;
	return (node);
}

void	free_lst(t_container *cont)
{
	size_t	i;
	t_stack	*node;
	t_stack	*next_node;

	i = 0;
	node = cont->stack;
	while (i < cont->len)
	{
		next_node = node->next;
		free(node);
		node = next_node;
		i++;
	}
	cont->stack = NULL;
}

void	add_node(t_container *container, t_stack *node)
{
	if (container->stack == NULL)
		container->stack = node;
	else
	{
		node->before = container->stack->before;
		node->next = container->stack;
		container->stack->before->next = node;
		container->stack->before = node;
	}
}
