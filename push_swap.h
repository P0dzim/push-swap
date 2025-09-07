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

# define INT_EXPLOSION 3000000000
# define INT_HIGH	2147483647 
# define INT_LOW	-2147483648

# include "libft/libft.h"

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos;
	int	target_pos;
	int	cost_a;
	int	cost_b;
}		t_stack;

typedef struct s_array
{
	t_stack	*stack;
	int		beggin;
	int		end;
	int		len;
}			t_array;

t_array	init_array(int len);
long	ft_atol_checker(const char *nptr);
void	create_stack(char **tab);
int		fill_stack(t_stack *stack, char **tab);
int		its_sorted(t_array *array);

void	pa_move(t_array *array_a, t_array *array_b);
void	pb_move(t_array *array_a, t_array *array_b);

void	sa_move(t_array *array_a);
void	sb_move(t_array *array_b);
void	ss_move(t_array *array_a, t_array *array_b);

void	ra_move(t_array *array_a);
void	rb_move(t_array *array_b);
void	rr_move(t_array *array_a, t_array *array_b);

void	rra_move(t_array *array_a);
void	rrb_move(t_array *array_b);
void	rrr_move(t_array *array_a, t_array *array_b);

void	sort_three(t_array *array);

#endif