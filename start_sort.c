/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:01:13 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/09 12:01:14 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_container contA)
{
	t_container contB;

	contB.stack = NULL;
	contB.len = 0;
	if (!its_sorted(&contA))
	{
		if (contA.len == 2)
			ra_move(&contA);
		else if (contA.len == 3)
			sort_three(&contA);
		else
			many_sort(&contA, &contB);
	}
	free_lst(&contA);
}

