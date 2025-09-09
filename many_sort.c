/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 14:53:58 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 14:54:00 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	many_sort(t_container *contA, t_container *contB)
{
	while (contA->len > 3)
		pb_move(contA, contB);
	while (contB->len > 0)
		pa_move(contA, contB);
}
