/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_position_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:20:24 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 11:43:56 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	update_pos(t_container *cont)
{
	t_stack	*node;
	size_t	i;

	i = 0;
	node = cont->stack;
	while (i < cont->len)
	{
		node->pos = i;
		node = node->next;
		i++;
	}
}
