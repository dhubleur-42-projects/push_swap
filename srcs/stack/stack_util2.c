/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 09:48:21 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/07 11:33:48 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_op_to_go_up(t_stack *stack, int value)
{
	if (get_index(stack, value) + 1 <= count_stack_elements(stack) / 2)
		return (get_index(stack, value));
	else
		return (count_stack_elements(stack) - get_index(stack, value));
}

int	get_element_to_top(t_stack *stack, int chunk)
{
	int	best;
	int	operations;
	int	tmp;

	operations = 2147483647;
	while (stack != NULL)
	{
		if (stack->value <= chunk)
		{
			tmp = count_op_to_go_up(stack, stack->value);
			if (tmp < operations)
			{
				best = stack->value;
				operations = tmp;
			}
		}
		stack = stack->next;
	}
	return (best);
}

t_stack	*get_sorted_stack(t_stack *stack)
{
	t_stack	*sorted;
	int		i;
	int		last;
	int		tmp;
	t_stack	*elem;

	sorted = NULL;
	add_to_stack_bottom(&sorted, new_stack_elem(find_smallest(stack)));
	last = find_smallest(stack);
	i = 0;
	while (++i < count_stack_elements(stack))
	{
		tmp = 2147483647;
		elem = stack;
		while (elem != NULL)
		{
			if (elem->value < tmp && elem->value > last)
				tmp = elem->value;
			elem = elem->next;
		}
		add_to_stack_bottom(&sorted, new_stack_elem(tmp));
		last = tmp;
	}
	return (sorted);
}

void	push_to_top_a(t_stack **stack, int value)
{
	if (get_index(*stack, value) + 1 <= count_stack_elements(*stack) / 2)
	{
		while ((*stack)->value != value)
			execute_ra(stack);
	}
	else
	{
		while ((*stack)->value != value)
			execute_rra(stack);
	}
}

void	push_to_top(t_stack **stack, int value, char stack_name)
{
	if (stack_name == 'a')
		push_to_top_a(stack, value);
	if (stack_name == 'b')
	{
		if (get_index(*stack, value) + 1 <= count_stack_elements(*stack) / 2)
		{
			while ((*stack)->value != value)
				execute_rb(stack);
		}
		else
		{
			while ((*stack)->value != value)
				execute_rrb(stack);
		}
	}
}
