/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <vitosant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:50:08 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/12 16:29:38 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_EXPLOSION 5000000000
# define INT_HIGH	2147483647 
# define INT_LOW	-2147483648
# define A	0
# define B 	1

# include "libft.h"

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
}			t_container;

long	ft_atol_checker(char *nptr);
int		fill_array(t_array *stack, char **tab);
void	create_stack(char **tab);
void	update_pos(t_container *cont);
int		is_sorted(t_container *cont);
void	sign_cost(t_container *cont_a, t_container *cont_b);
size_t	positive_num(ssize_t nbr);
void	shortcut_way(t_container *cont_a, t_container *cont_b);
ssize_t	find_upper_bound(t_container *cont, size_t target);
ssize_t	find_lower_bound(t_container *cont, size_t target);

void	free_lst(t_container *cont);
void	fill_lst(t_array *array, t_container *container);
void	add_node(t_container *container, t_stack *node);

void	start_sort(t_container cont_a);
void	sort_three(t_container *cont);
void	the_big_sort(t_container *cont_a, t_container *cont_b);

void	reverse_a(t_container *cont);
void	reverse_b(t_container *cont);
void	reverse_r(t_container *cont_a, t_container *cont_b);

void	ra_move(t_container *cont_a);
void	rb_move(t_container *cont);
void	rr_move(t_container *cont_a, t_container *cont_b);

void	pa_move(t_container *cont_a, t_container *cont_b);
void	pb_move(t_container *cont_a, t_container *cont_b);

void	sa_move(t_container *cont);
void	sb_move(t_container *cont);
void	ss_move(t_container *cont_a, t_container *cont_b);

#endif