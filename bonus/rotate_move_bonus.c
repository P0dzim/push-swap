/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:06:27 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 14:34:10 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate_move(t_container *cont)
{
	if (!cont->stack)
		return ;
	cont->stack = cont->stack->next;
	update_pos(cont);
}

void	r_operation(t_container *cont_a, t_container *cont_b, int i)
{
	if (i == 3)
		rotate_move(cont_a);
	else if (i == 4)
		rotate_move(cont_b);
	else
	{
		rotate_move(cont_a);
		rotate_move(cont_b);
	}
}
