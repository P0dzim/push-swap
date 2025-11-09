/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_checker_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 09:31:14 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 16:40:55 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	skip_zero(char **nptr, int j);

long	ft_atol_checker(char *nptr)
{
	long	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	skip_zero(&nptr, i);
	while (nptr[i] >= '0' && nptr[i] <= '9' && i <= 11)
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] != '\0' || (i >= 1
			&& (nptr[i - 1] == '+' || nptr[i - 1] == '-')))
		return (INT_EXPLOSION);
	return (num * sign);
}

static void	skip_zero(char **nptr, int j)
{
	int	i;

	i = 0;
	while (nptr[0][(i + j)] == '0')
		i++;
	nptr[0] = &nptr[0][i];
}
