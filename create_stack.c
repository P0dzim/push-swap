/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:35:09 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 14:35:11 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(char **tab)
{
	t_array	array;
	int		len;

	len = ft_tablen(tab);
	array = init_array(len);
	if (fill_stack(array.stack, tab) == -1)
	{
		ft_printf("Error\n");
		free(array.stack);
		return ;
	}
	if (!its_sorted(&array))
	{
		if (len == 2)
			sa_move(&array);
		else if (len == 3)
			sort_three(&array);
		else
			ft_printf("\naqui mais\n");
	}
	free(array.stack);
}
