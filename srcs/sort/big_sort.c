/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:31:33 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/07 11:36:45 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sorted_index(t_stack **stack_a)
{
	t_stack	*sorted;
	t_stack	*stock;
	t_stack	*elem;
	int		index;

	sorted = get_sorted_stack(*stack_a);
	stock = sorted;
	index = 0;
	while (sorted != NULL)
	{
		elem = *stack_a;
		while (elem != NULL)
		{
			if (elem->value == sorted->value)
				elem->sorted_index = index;
			elem = elem->next;
		}
		sorted = sorted->next;
		index++;
	}
	free_stack(&stock);
}

int	get_increasing_sequence(t_stack *start_elem,
	t_stack **stack, t_bool definitive)
{
	t_stack		*elem;
	int			index_max;
	int			count;

	elem = start_elem;
	index_max = 0;
	count = 0;
	while (elem)
	{
		if (elem->sorted_index >= index_max)
		{
			if (definitive)
				elem->keep = TRUE;
			index_max = elem->sorted_index;
			++count;
		}
		else if (definitive)
			elem->keep = FALSE;
		elem = elem->next;
		if (elem == NULL)
			elem = *stack;
		if (elem == start_elem)
			break ;
	}
	return (count);
}

t_stack	*get_first_element_of_sequence(t_stack **stack)
{
	t_stack	*elem;
	t_stack	*max;
	int		max_keep;
	int		cur;

	max_keep = 0;
	elem = *stack;
	while (elem)
	{
		cur = get_increasing_sequence(elem, stack, FALSE);
		if (cur > max_keep)
		{
			max_keep = cur;
			max = elem;
		}
		elem = elem->next;
	}
	return (max);
}

int	set_keep_sequence(t_stack **stack)
{
	t_stack		*max;

	max = get_first_element_of_sequence(stack);
	return (get_increasing_sequence(max, stack, TRUE));
}

void	push_to_b_not_in_sequence(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = count_stack_elements(*stack_a) - set_keep_sequence(stack_a);
	while (size > 0)
	{
		if ((*stack_a)->keep == FALSE)
		{
			execute_pb(stack_a, stack_b);
			size--;
		}
		else
			execute_ra(stack_a);
	}
}
