/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:45:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 10:45:56 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_stack_bottom(t_stack **alst, t_stack *new)
{
	t_stack	*ptr;

	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_stack	*new_stack_elem(int value)
{
	t_stack	*obj;

	obj = malloc(sizeof(t_stack));
	if (!obj)
		return (NULL);
	obj->value = value;
	obj->next = NULL;
	return (obj);
}

t_bool	is_sort(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->next->value < stack->value)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

int	count_stack_elements(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
