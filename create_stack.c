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
	t_stack	*stack;

	stack = malloc(ft_tablen(tab) * sizeof(t_stack));
	if (fill_stack(stack, tab) == -1)
	{
		ft_printf("Error\n");
		free(stack);
		return ;
	}
}
