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
static void	sign_postion(t_stack *stack, int len);
static void	sort_array(int *ref_stack, int len);
static void	put_position(t_stack *stack, int *ref_stack, int len);

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
	sign_postion(stack, i);
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

static void	sign_postion(t_stack *stack, int len)
{
	int	i;
	int	*ref_stack;

	i = 0;
	ref_stack = malloc(len * sizeof(int));
	if (!ref_stack)
		return ;
	while (i < len)
	{
		ref_stack[i] = stack[i].value;
		i++;
	}
	sort_array(ref_stack, len);
	put_position(stack, ref_stack, len);
	free(ref_stack);
}

static void	sort_array(int *ref_stack, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ref_stack[j] < ref_stack[i])
			{
				temp = ref_stack[j];
				ref_stack[j] = ref_stack[i];
				ref_stack[i] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	put_position(t_stack *stack, int *ref_stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[j].value == ref_stack[i])
			{
				stack[j].target_pos = i;
				break ;
			}
			j++;
		}
		i++;
	}
}
