/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:40:48 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/07 11:57:34 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_in_same_way(t_stack **stack_a,
	t_stack **stack_b, t_backpack *backpack)
{
	while (backpack->min_for_b > 0 && backpack->min_for_a > 0)
	{
		execute_rr(stack_a, stack_b);
		backpack->min_for_b--;
		backpack->min_for_a--;
	}
	while (backpack->min_for_a < 0 && backpack->min_for_b < 0)
	{
		execute_rrr(stack_a, stack_b);
		backpack->min_for_b++;
		backpack->min_for_a++;
	}
}

void	execute_actions(t_stack **stack_a,
	t_stack **stack_b, t_backpack *backpack)
{
	if ((backpack->min_for_b > 0 && backpack->min_for_a > 0)
		|| (backpack->min_for_b < 0 && backpack->min_for_a < 0))
		rotate_in_same_way(stack_a, stack_b, backpack);
	while (backpack->min_for_b > 0)
	{
		execute_rb(stack_b);
		(backpack->min_for_b)--;
	}
	while (backpack->min_for_b < 0)
	{
		execute_rrb(stack_b);
		(backpack->min_for_b)++;
	}
	while (backpack->min_for_a > 0)
	{
		execute_ra(stack_a);
		(backpack->min_for_a)--;
	}
	while (backpack->min_for_a < 0)
	{
		execute_rra(stack_a);
		(backpack->min_for_a)++;
	}
	execute_pa(stack_a, stack_b);
}

void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_backpack	backpack;

	set_sorted_index(stack_a);
	push_to_b_not_in_sequence(stack_a, stack_b);
	while (count_stack_elements(*stack_b) > 0)
	{
		backpack.b_element = *stack_b;
		get_min_actions(stack_a, stack_b, &backpack);
		execute_actions(stack_a, stack_b, &backpack);
	}
	push_to_top(stack_a, find_smallest(*stack_a), 'a');
}
