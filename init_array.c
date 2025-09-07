/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 18:24:48 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/07 13:13:36 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_array	init_array(int len)
{
	t_array	array;

	array.stack = malloc(len * sizeof(t_stack));
	array.beggin = 0;
	array.end = len - 1;
	array.len = len;
	return (array);
}
