/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9stack_utility.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:46:17 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/30 15:46:01 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * find_min - Finds the minimum index within the stack.
 * @a: Pointer to the top of the stack.
 *
 * Iterates through the entire stack to find the node with the minimum index.
 * This utility is crucial for deciding sorting strategies, especially when
 * sorting small numbers of elements (like 3) where the position of the minimum
 * value can determine the most efficient set of operations.
 *
 * Return: The minimum index found in the stack.
 */
int find_min_index(t_stack *a)
{
	int i;

	i = a->index;
	while(a)
	{
		if (a->index < i)
			i = a->index;
		a = a->next;
	}
	return(i);
}

/*
 * find_max - Finds the maximum index within the stack.
 * @a: Pointer to the top of the stack.
 *
 * Searches through the stack to identify the node with the maximum index.
 * Similar to find_min, this function supports sorting logic by identifying
 * the maximum value's position, facilitating efficient sorting strategy choices.
 *
 * Return: The maximum index present in the stack.
 */
int find_max_index(t_stack *a)
{
	int i;

	i = a->index;
	while(a)
	{
		if (a->index > i)
			i = a->index;
		a = a->next;
	}
	return(i);
}

/*
 * stack_size - Counts the number of nodes in a stack.
 * @stack: Pointer to the top of the stack.
 *
 * This function iterates through the doubly linked list represented by
 * the stack and counts the number of nodes until it reaches the end.
 * It's designed to work with stacks of any size, from empty to fully populated.
 * The doubly linked nature of the stack does not affect this function's
 * operation, as it only traverses in one direction (forward) to count the nodes.
 *
 * Return: The total number of nodes in the stack.
 */
int get_stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int find_min_position(t_stack *stack_a)
{
	int min_index;
	int position;
	t_stack *current;

	min_index = find_min_index(stack_a);
	current = stack_a;
	position = 0;
	while(current != NULL)
	{
		if (current->index == min_index)
			return (position);
		current = current->next;
		position++;
	}
	return(-1);
}

void free_stack(t_stack **stack)
{
	t_stack *tmp;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}