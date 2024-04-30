/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4populate_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:46:01 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/29 13:09:26 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * create_new_node - Initializes a stack node with a given index.
 * @index: Sorted position of the node's value.
 *
 * Prepares a node for the stack where 'index' represents the value's 
 * sorted position, critical for executing stack operations based on 
 * relative ordering instead of raw values.
 * Return: New node, or NULL on failure.
 */
static t_stack	*create_new_node(int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->index = index;
	node->next = NULL;
	return (node);
}
/*
 * find_index - Locates the index of @value in @sorted.
 * @sorted: Sorted array for lookup.
 * @size: Size of the sorted array.
 * @value: Value to find the index for.
 * 
 * Returns the index of @value within the sorted array @sorted,
 * essential for mapping to the stack nodes.
 * Return: Index of @value, or -1 if not found.
 */

static int	find_arr_index(const int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
/*
 * append_node_to_stack - Appends a new node to the end of the stack.
 * @stack_a: Pointer to the first node of the stack, if it exists.
 * @new_node: The new node to be added to the stack.
 *
 * This function appends @new_node to the end of the stack pointed to by
 * @stack_a. It traverses the stack to find the last node and links @new_node
 * as its successor, maintaining the doubly linked list structure. This
 * ensures that the stack grows from the end, preserving the original input
 * order with the earliest parsed value at the top of the stack when processed
 * in reverse order of input.
 */

static void	append_node_to_stack(t_stack **stack_a, t_stack *new_node)
{
	t_stack	*current;

	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		current = *stack_a;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
}
/*
 * populate_stack_a - Populates stack_a with nodes based on original input order.
 * @stack_a: Double pointer to the top node of stack_a.
 * @original: Array of original, unsorted values as received from input.
 * @sorted: Array of the same values sorted to determine relative positions.
 * @size: The number of elements in both @original and @sorted arrays.
 *
 * For each value in @original, this function locates its position in the
 * @sorted array (its "index") and creates a new stack node with this index.
 * It then appends each node to the end of @stack_a, ensuring that
 * the stack is populated in the same order as the original input, with the
 * first input value at the top of the stack.
 */

int	populate_stack_a(t_stack **stack_a, int *orig, int *sorted, int size)
{
	int		i;
	int		index;
	t_stack	*new_node;

	i = 0;
	while (i < size)
	{
		index = find_arr_index(sorted, size, orig[i]);
		if (index == -1)
			return (0);
		new_node = create_new_node(index);
		if (new_node == NULL)
			return (0);
		append_node_to_stack(stack_a, new_node);
		i++;
	}
	return (1);
}
