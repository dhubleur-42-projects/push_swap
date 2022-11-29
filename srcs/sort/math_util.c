/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:56:28 by dhubleur          #+#    #+#             */
/*   Updated: 2022/01/07 11:41:36 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs_value(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

int	max(int i1, int i2)
{
	if (i1 > i2)
		return (i1);
	return (i2);
}
