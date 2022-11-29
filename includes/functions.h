/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:29:16 by dhubleur          #+#    #+#             */
/*   Updated: 2021/12/08 10:29:16 by dhubleur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

//Parse
t_bool	parse_args(int argc, char **argv, t_stack **stack);

//Stack util
void	add_to_stack_bottom(t_stack **alst, t_stack *new);
t_stack	*new_stack_elem(int value);
t_bool	is_sort(t_stack *stack);
int		count_stack_elements(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
int		get_index(t_stack *stack, int value);
void	push_to_top(t_stack **stack, int value, char stack_name);
int		find_2smallest(t_stack *stack, int min);
int		get_value(t_stack *stack, int index);
int		count_op_to_go_up(t_stack *stack, int value);
t_bool	free_stack(t_stack **stack);

//Actions
void	execute_sa(t_stack **stack_a);
void	execute_sb(t_stack **stack_b);
void	execute_ss(t_stack **stack_a, t_stack **stack_b);
void	execute_pa(t_stack **stack_a, t_stack **stack_b);
void	execute_pb(t_stack **stack_a, t_stack **stack_b);
void	execute_ra(t_stack **stack_a);
void	execute_rb(t_stack **stack_b);
void	execute_rr(t_stack **stack_a, t_stack **stack_b);
void	execute_rra(t_stack **stack_a);
void	execute_rrb(t_stack **stack_b);
void	execute_rrr(t_stack **stack_a, t_stack **stack_b);

//Sort
void	start_sort(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_sorted_stack(t_stack *stack);
int		get_element_to_top(t_stack *stack, int chunk);
void	sort_big_stack(t_stack **stack_a, t_stack **stack_b);
void	set_sorted_index(t_stack **stack_a);
void	push_to_b_not_in_sequence(t_stack **stack_a, t_stack **stack_b);
t_stack	*get_min_actions(t_stack **stack_a, t_stack **stack_b,
			t_backpack *backpack);

//Math
int		abs_value(int i);
int		min(int i1, int i2);
int		max(int i1, int i2);

#endif