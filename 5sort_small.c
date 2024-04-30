/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5sort_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 13:47:48 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/30 15:27:43 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		do_sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	t_stack	*last;

	if (find_min_index(*stack_a) == (*stack_a)->index)
	{
		do_rra(stack_a);
		do_sa(stack_a);
	}
	else if (find_max_index(*stack_a) == (*stack_a)->index)
	{
		do_ra(stack_a);
		if (!is_sorted(*stack_a))
			do_sa(stack_a);
	}
	else
	{
		last = stack_last(*stack_a);
		if (last->index == find_min_index(*stack_a))
			do_rra(stack_a);
		else
			do_sa(stack_a);
	}
}

void rotate_to_top(t_stack **stack_a, int target_position)
{
	int stack_size;
	int midpoint;

	stack_size = get_stack_size(*stack_a);
	midpoint = stack_size / 2;
	if (target_position <= midpoint)
	{
		while (target_position > 0)
		{
			do_ra(stack_a);
			target_position--;
		}
	}
	else
	{
		while (stack_size - target_position > 0)
		{
			do_rra(stack_a);
			stack_size--;
		}
	}
}

void sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int min_pos;

	i = 0;
	while (i < 2)
	{
		min_pos = find_min_position(*stack_a);
		rotate_to_top(stack_a, min_pos);
		do_pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	i = 0;
	while (i < 2)
	{
		do_pa(stack_b, stack_a);
		i++;
	}
}

void sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int min_pos;

	min_pos = find_min_position(*stack_a);
	rotate_to_top(stack_a, min_pos);
	do_pb(stack_a, stack_b);
	sort_three(stack_a);
	do_pa(stack_b, stack_a);
}
