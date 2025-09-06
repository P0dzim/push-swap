/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 14:40:20 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 14:40:21 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_repeated(t_stack *stack, int i, int nbr);

int	fill_stack(t_stack *stack, char **tab)
{
	long	nbr;
	int		i;

	i = 0;
	if (!stack)
		return (-1);
	while (tab[i])
	{
		nbr = ft_atol_checker(tab[i]);
		if (nbr < INT_LOW || nbr > INT_HIGH || is_repeated(stack, i, (int)nbr))
			break ;
		stack[i].value = (int)nbr;
		stack[i].index = i;
		stack[i].pos = i;
		i++;
	}
	if (tab[i] != NULL)
		return (-1);
	return (0);
}

static int	is_repeated(t_stack *stack, int i, int nbr)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (stack[j].value == nbr)
			break ;
		j++;
	}
	if (j == i)
		return (0);
	return (j + 1);
}
