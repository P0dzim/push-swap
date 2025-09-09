/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:22:10 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 14:22:14 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	higher_top(t_container *cont);
static void	higher_mid(t_container *cont);

void	sort_three(t_container *cont)
{
	int	value[3];

	value[0] = cont->stack->value;
	value[1] = cont->stack->next->value;
	value[2] = cont->stack->before->value;

	if (its_sorted(cont))
		return ;
	if (value[0] > value[1] && value[0] > value[2])
		higher_top(cont);
	else if (value[1] > value[2] && value[1] > value[0])
		higher_mid(cont);
	else
		sa_move(cont);
}

static void	higher_top(t_container *cont)
{
	ra_move(cont);
	if (its_sorted(cont))
		return ;
	sa_move(cont);
}

static void	higher_mid(t_container *cont)
{
	reverse_a(cont);
	if (its_sorted(cont))
		return ;
	sa_move(cont);
}