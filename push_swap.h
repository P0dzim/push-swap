/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitosant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:50:08 by vitosant          #+#    #+#             */
/*   Updated: 2025/09/06 11:50:11 by vitosant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	ssize_t			costA;
	ssize_t			costB;
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


long	ft_atol_checker(const char *nptr);
int		fill_array(t_array *stack, char **tab);
void	create_stack(char **tab);
void	update_pos(t_container *cont);
int		its_sorted(t_container *cont);
void	sing_cost(t_container *contA, t_container *contB);
size_t	positive_num(ssize_t nbr);
void	shortcut_way(t_container *contA, t_container *contB);

void	free_lst(t_container *cont);
void	fill_lst(t_array *array, t_container *container);
void	add_node(t_container *container, t_stack *node);

void	start_sort(t_container contA);
void	sort_three(t_container *cont);
void	many_sort(t_container *contA, t_container *contB);

void	reverse_a(t_container *cont);
void	reverse_b(t_container *cont);
void	reverse_r(t_container *contA, t_container *contB);

void	ra_move(t_container *contA);
void	rb_move(t_container *cont);
void	rr_move(t_container *contA, t_container *contB);

void	pa_move(t_container *contA, t_container *contB);
void	pb_move(t_container *contA, t_container *contB);

void	sa_move(t_container *cont);
void	sb_move(t_container *cont);
void	ss_move(t_container *contA, t_container *contB);

#endif