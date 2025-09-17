/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 10:58:53 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/16 09:20:10 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	beggin_check(t_container *cont_a, t_container *cont_b);
static void	get_operation(t_container *cont_a, t_container *cont_b);
static void	init_options(t_option *function);
static int	is_invalid_operation(char *str, t_container *cont, t_option *func);

void	create_stack(char **tab)
{
	t_array		*tmp;
	t_container	cont_a;
	t_container	cont_b;

	tmp = malloc(ft_tablen(tab) * sizeof(t_array));
	if (fill_array(tmp, tab) == -1 || *tab == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		if (tmp)
			free(tmp);
		return ;
	}
	cont_a.stack = NULL;
	cont_a.len = ft_tablen(tab);
	cont_a.total = ft_tablen(tab);
	cont_a.all_valid = 1;
	fill_lst(tmp, &cont_a);
	free(tmp);
	cont_b.total = cont_a.total;
	cont_b.stack = NULL;
	cont_b.len = 0;
	beggin_check(&cont_a, &cont_b);
	free_lst(&cont_a);
	free_lst(&cont_b);
}

static void	beggin_check(t_container *cont_a, t_container *cont_b)
{
	get_operation(cont_a, cont_b);
	if (is_sorted(cont_a) && cont_a->all_valid)
		ft_putstr_fd("OK\n", 1);
	else if (cont_a->all_valid)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("Error\n", 2);
}

static void	get_operation(t_container *cont_a, t_container *cont_b)
{
	char		*str;
	int			i;
	t_option	function[11];

	init_options(function);
	while (1)
	{
		str = get_next_line(0);
		if (!str || is_invalid_operation(str, cont_a, function))
			break ;
		i = 0;
		while (i <= 10)
		{
			if (ft_strncmp(function[i].opt, str, 10) == 0)
				function[i].function(cont_a, cont_b, i);
			i++;
		}
		free(str);
	}
	if (str)
		free(str);
}

static int	is_invalid_operation(char *str, t_container *cont, t_option *func)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 10)
	{
		if (ft_strncmp(func[i].opt, str, 10) == 0)
			j = 0;
		i++;
	}
	if (j)
		cont->all_valid = 0;
	return (j);
}

static void	init_options(t_option *function)
{
	function[0].opt = "sa\n";
	function[0].function = s_operation;
	function[1].opt = "sb\n";
	function[1].function = s_operation;
	function[2].opt = "ss\n";
	function[2].function = s_operation;
	function[3].opt = "ra\n";
	function[3].function = r_operation;
	function[4].opt = "rb\n";
	function[4].function = r_operation;
	function[5].opt = "rr\n";
	function[5].function = r_operation;
	function[6].opt = "rra\n";
	function[6].function = rr_operation;
	function[7].opt = "rrb\n";
	function[7].function = rr_operation;
	function[8].opt = "rrr\n";
	function[8].function = rr_operation;
	function[9].opt = "pa\n";
	function[9].function = p_operation;
	function[10].opt = "pb\n";
	function[10].function = p_operation;
}
