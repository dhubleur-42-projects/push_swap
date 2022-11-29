/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:24:17 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 10:24:17 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_stack
{
	int				value;
	t_bool			keep;
	int				sorted_index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_backpack
{
	t_stack	*b_element;
	t_stack	*best_element;
	int		move_for_a;
	int		move_for_b;
	int		total_min_move;
	int		total_move;
	int		actions_for_b;
	int		min_for_a;
	int		min_for_b;
}				t_backpack;

#endif