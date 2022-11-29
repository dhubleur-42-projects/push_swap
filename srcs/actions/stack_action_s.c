/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:02:38 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 11:02:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	execute_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*third;

	first = *stack;
	if (first != NULL && first->next != NULL)
	{
		first = *stack;
		third = first->next->next;
		*stack = first->next;
		(*stack)->next = first;
		(*stack)->next->next = third;
		return (TRUE);
	}
	return (FALSE);
}

void	execute_sa(t_stack **stack_a)
{
	if (execute_swap(stack_a))
		ft_putendl_fd("sa", 1);
}

void	execute_sb(t_stack **stack_b)
{
	if (execute_swap(stack_b))
		ft_putendl_fd("sb", 1);
}

void	execute_ss(t_stack **stack_a, t_stack **stack_b)
{
	if (execute_swap(stack_a) || execute_swap(stack_b))
		ft_putendl_fd("ss", 1);
}
