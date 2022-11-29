/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:28:56 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 20:48:44 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*elem;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		*stack = first->next;
		elem = *stack;
		while (elem->next != NULL)
			elem = elem->next;
		elem->next = first;
		first->next = NULL;
	}
}

void	execute_ra(t_stack **stack_a)
{
	execute_rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	execute_rb(t_stack **stack_b)
{
	execute_rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	execute_rr(t_stack **stack_a, t_stack **stack_b)
{
	execute_rotate(stack_a);
	execute_rotate(stack_b);
	ft_putendl_fd("rr", 1);
}
