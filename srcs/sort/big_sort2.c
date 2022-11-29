/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:35:30 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/10 11:09:13 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_optimized_actions(int move_for_a, int move_for_b)
{
	if (move_for_a > 0 && move_for_b > 0)
		return (abs_value(move_for_a) + abs_value(move_for_b)
			- min(move_for_a, move_for_b));
	else if (move_for_a < 0 && move_for_b < 0)
		return (abs_value(move_for_a) + abs_value(move_for_b)
			+ max(move_for_a, move_for_b));
	else
		return (abs_value(move_for_a) + abs_value(move_for_b));
}

void	init(int *i, int *pos, t_bool *end)
{
	*i = 1;
	*pos = 0;
	*end = FALSE;
}

int	get_pos_of_elem_in_a(t_stack **stack_a, int elem_to_push_idx,
	t_stack *next_elem, t_stack *prev_elem)
{
	int			i;
	int			pos;
	t_bool		end;

	init(&i, &pos, &end);
	while (prev_elem && !end)
	{
		if (next_elem == NULL)
		{
			next_elem = *stack_a;
			end = TRUE;
		}
		if ((elem_to_push_idx > prev_elem->sorted_index
				&& elem_to_push_idx < next_elem->sorted_index)
			|| (prev_elem->sorted_index > next_elem->sorted_index
				&& (elem_to_push_idx < next_elem->sorted_index
					|| elem_to_push_idx > prev_elem->sorted_index)))
			pos = i;
		i++;
		prev_elem = next_elem;
		next_elem = next_elem->next;
	}
	if (pos > count_stack_elements(*stack_a) / 2)
		pos -= count_stack_elements(*stack_a);
	return (pos);
}

void	set_good_informations(t_backpack *backpack)
{
	backpack->total_min_move = backpack->total_move;
	backpack->best_element = backpack->b_element;
	backpack->min_for_a = backpack->move_for_a;
	backpack->min_for_b = backpack->actions_for_b;
}

t_stack	*get_min_actions(t_stack **stack_a, t_stack **stack_b,
	t_backpack *backpack)
{
	t_stack	*tmp;
	t_stack	*prev_element;

	backpack->move_for_b = 0;
	backpack->total_min_move = 2147483647;
	while (backpack->b_element)
	{
		tmp = (*stack_a)->next;
		prev_element = *stack_a;
		backpack->move_for_a = get_pos_of_elem_in_a
			(stack_a, backpack->b_element->sorted_index, tmp, prev_element);
		backpack->actions_for_b = backpack->move_for_b;
		if (backpack->move_for_b > count_stack_elements(*stack_b) / 2)
			backpack->actions_for_b -= count_stack_elements(*stack_b);
		backpack->total_move = count_optimized_actions
			(backpack->move_for_a, backpack->move_for_b);
		if (backpack->total_move < backpack->total_min_move)
			set_good_informations(backpack);
		backpack->b_element = backpack->b_element->next;
		(backpack->move_for_b)++;
	}
	return (backpack->best_element);
}
