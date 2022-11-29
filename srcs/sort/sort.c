/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:24:27 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/06 14:21:19 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3elements(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first < third && second > third)
	{
		execute_rra(stack_a);
		execute_sa(stack_a);
	}
	if (first > second && first < third)
		execute_sa(stack_a);
	if (first < second && first > third)
		execute_rra(stack_a);
	if (first > third && second < third)
		execute_ra(stack_a);
	if (first > second && second > third)
	{
		execute_ra(stack_a);
		execute_sa(stack_a);
	}
}

void	sort_4elements(t_stack **stack_a, t_stack **stack_b)
{
	push_to_top(stack_a, find_smallest(*stack_a), 'a');
	execute_pb(stack_a, stack_b);
	sort_3elements(stack_a);
	execute_pa(stack_a, stack_b);
}

void	sort_5elements(t_stack **stack_a, t_stack **stack_b)
{
	int		min1;
	int		min2;
	int		count;
	int		i;

	min1 = find_smallest(*stack_a);
	min2 = find_2smallest(*stack_a, min1);
	i = -1;
	count = count_stack_elements(*stack_a);
	while (++i < count)
	{
		if ((*stack_a)->value == min1 || (*stack_a)->value == min2)
			execute_pb(stack_a, stack_b);
		else
			execute_ra(stack_a);
		if (count_stack_elements(*stack_b) == 2)
			break ;
	}
	if (is_sort(*stack_b))
		execute_sb(stack_b);
	sort_3elements(stack_a);
	execute_pa(stack_a, stack_b);
	execute_pa(stack_a, stack_b);
}

void	start_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = count_stack_elements(*stack_a);
	if (count == 2)
		execute_ra(stack_a);
	else if (count == 3)
		sort_3elements(stack_a);
	else if (count == 4)
		sort_4elements(stack_a, stack_b);
	else if (count == 5)
		sort_5elements(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
}
