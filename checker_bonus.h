/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:12:44 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/16 08:59:12 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define INT_EXPLOSION 5000000000
# define INT_HIGH	2147483647 
# define INT_LOW	-2147483648
# define A	0
# define B 	1

# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	size_t			pos;
	size_t			target_pos;
	ssize_t			cost_a;
	ssize_t			cost_b;
	struct s_stack	*next;
	struct s_stack	*before;
}					t_stack;

typedef struct s_array
{
	int		value;
	size_t	pos;
	size_t	target_pos;
}		t_array;

typedef struct s_container
{
	t_stack	*stack;
	size_t	len;
	size_t	total;
	int		all_valid;
}			t_container;

typedef struct s_options
{
	char	*opt;
	void	(*function)(t_container *, t_container *, int);	
}			t_option;

long	ft_atol_checker(char *nptr);
int		fill_array(t_array *stack, char **tab);
void	create_stack(char **tab);
void	update_pos(t_container *cont);
int		is_sorted(t_container *cont);

void	free_lst(t_container *cont);
void	fill_lst(t_array *array, t_container *container);
void	add_node(t_container *container, t_stack *node);

void	s_operation(t_container *cont_a, t_container *cont_b, int i);
void	r_operation(t_container *cont_a, t_container *cont_b, int i);
void	rr_operation(t_container *cont_a, t_container *cont_b, int i);
void	p_operation(t_container *cont_a, t_container *cont_b, int i);
#endif