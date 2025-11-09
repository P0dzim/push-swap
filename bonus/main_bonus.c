/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:42:28 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 14:40:11 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	char	**tab;
	char	**temp[2];
	int		i;

	i = 2;
	if (argc <= 1)
		return (1);
	tab = ft_split(argv[1], ' ');
	while (i < argc)
	{
		temp[0] = tab;
		temp[1] = ft_split(argv[i], ' ');
		tab = ft_tabjoin(temp[0], temp[1]);
		free(temp[0]);
		free(temp[1]);
		i++;
	}
	create_stack(tab);
	ft_free_table(&tab);
	return (0);
}
