/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_rr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:59:04 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 10:29:05 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_reverse_rotate(t_stack **stack)
{
	t_stack	*elem;
	t_stack	*first;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		first = *stack;
		elem = *stack;
		while (elem->next->next != NULL)
			elem = elem->next;
		*stack = elem->next;
		(*stack)->next = first;
		elem->next = NULL;
	}
}

void	execute_rra(t_stack **stack_a)
{
	execute_reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	execute_rrb(t_stack **stack_b)
{
	execute_reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	execute_rrr(t_stack **stack_a, t_stack **stack_b)
{
	execute_reverse_rotate(stack_a);
	execute_reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}
