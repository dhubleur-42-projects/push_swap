/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_action_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:11:41 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/10 10:55:25 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	execute_push(t_stack **from, t_stack **to)
{
	t_stack	*elem;
	t_stack	*ancien_first;

	elem = *from;
	if (elem == NULL)
		return (FALSE);
	*from = elem->next;
	ancien_first = *to;
	*to = elem;
	(*to)->next = ancien_first;
	return (TRUE);
}

void	execute_pa(t_stack **stack_a, t_stack **stack_b)
{
	if (execute_push(stack_b, stack_a))
		ft_putendl_fd("pa", 1);
}

void	execute_pb(t_stack **stack_a, t_stack **stack_b)
{
	if (execute_push(stack_a, stack_b))
		ft_putendl_fd("pb", 1);
}
