/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_move_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:12:59 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 14:31:47 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_move(t_container *cont)
{
	if (!cont->stack)
		return ;
	cont->stack = cont->stack->before;
	update_pos(cont);
}

void	rr_operation(t_container *cont_a, t_container *cont_b, int i)
{
	if (i == 6)
		reverse_move(cont_a);
	else if (i == 7)
		reverse_move(cont_b);
	else
	{
		reverse_move(cont_a);
		reverse_move(cont_b);
	}
}
