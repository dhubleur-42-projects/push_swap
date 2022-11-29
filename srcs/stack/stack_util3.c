/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:31:13 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/07 11:32:28 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		if (stack->value == value)
			return (i);
		i++;
		stack = stack->next;
	}
	return (-1);
}

int	find_biggest(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_smallest(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	find_2smallest(t_stack *stack, int min)
{
	int	min2;

	min2 = stack->value;
	if (min2 == min)
		min2 = stack->next->value;
	while (stack != NULL)
	{
		if (stack->value < min2 && stack->value > min)
			min2 = stack->value;
		stack = stack->next;
	}
	return (min2);
}

int	get_value(t_stack *stack, int index)
{
	int	i;

	i = 0;
	while (++i < index)
		stack = stack->next;
	return (stack->value);
}
