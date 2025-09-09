/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 09:31:14 by vitosant          #+#    #+#             */
/*   Updated: 2025/07/18 09:02:17 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol_checker(const char *nptr)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && i <= 11)
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' || (i >= 1 &&
		(nptr[i - 1] == '+' || nptr[i - 1] == '-')))
		return (INT_EXPLOSION);
	return (num * sign);
}
