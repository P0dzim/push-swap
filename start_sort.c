/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 12:01:13 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:42 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_sort(t_container cont_a)
{
	t_container	cont_b;

	cont_b.stack = NULL;
	cont_b.len = 0;
	cont_b.total = cont_a.total;
	if (!is_sorted(&cont_a))
	{
		if (cont_a.len == 2)
			ra_move(&cont_a);
		else if (cont_a.len == 3)
			sort_three(&cont_a);
		else
			the_big_sort(&cont_a, &cont_b);
	}
	free_lst(&cont_a);
}
