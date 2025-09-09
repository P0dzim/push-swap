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
	int				value;
	int				pos;
	int				target_pos;
	struct s_stack	*next;
	struct s_stack	*before;
}					t_stack;

typedef struct s_sentinel
{
	t_stack	*stack;
	int		len;
}			t_sentinel;


long	ft_atol_checker(const char *nptr);
void	create_stack(char **tab);

#endif