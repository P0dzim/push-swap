/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:58:53 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 08:30:02 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(char **tab)
{
	t_array		*tmp;
	t_container	cont;

	tmp = malloc(ft_tablen(tab) * sizeof(t_array));
	if (fill_array(tmp, tab) == -1 || *tab == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		if (tmp)
			free(tmp);
		return ;
	}
	cont.stack = NULL;
	cont.len = ft_tablen(tab);
	cont.total = ft_tablen(tab);
	fill_lst(tmp, &cont);
	free(tmp);
	start_sort(cont);
}
