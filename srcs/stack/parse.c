/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:27:38 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 10:27:38 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_num(char *str)
{
	int	i;

	i = -1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
		i++;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	return (TRUE);
}

t_bool	check_int(char *str)
{
	if (ft_strlen(str) > 11)
		return (FALSE);
	if (str[0] == '-')
	{
		if (ft_atoi(str) > 0)
			return (FALSE);
	}
	else
	{
		if (ft_atoi(str) < 0)
			return (FALSE);
	}
	return (TRUE);
}

t_bool	already_in_stack(int i, t_stack *stack)
{
	while (stack != NULL)
	{
		if (stack->value == i)
			return (TRUE);
		stack = stack->next;
	}
	return (FALSE);
}

t_bool	free_stack(t_stack **stack)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = *stack;
	*stack = NULL;
	while (ptr != NULL)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	return (FALSE);
}

t_bool	parse_args(int argc, char **argv, t_stack **stack)
{
	int		i;
	char	*arg;
	int		value;

	i = 0;
	while (++i < argc)
	{
		arg = argv[i];
		if (!check_num(arg))
			return (free_stack(stack));
		if (!check_int(arg))
			return (free_stack(stack));
		value = ft_atoi(arg);
		if (already_in_stack(value, *stack))
			return (free_stack(stack));
		add_to_stack_bottom(stack, new_stack_elem(value));
	}
	return (TRUE);
}
