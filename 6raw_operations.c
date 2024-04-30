/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6raw_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:25 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/29 13:10:53 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * push - Moves the top element from one stack to the top of another.
 * @src: The source stack from which the top element will be removed.
 * @dest: The destination stack where the removed element will be placed on top.
 *
 * This function takes the top element of the source stack and moves it
 * to the top of the destination stack.
 */
void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

/*
 * swap - Swaps the top two elements of a stack.
 * @stack: The stack whose top two elements will be swapped.
 *
 * If the stack contains fewer than two elements, the function does nothing.
 */
void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

/*
 * rotate - Rotates a stack downwards.
 * @stack: The stack to be rotated.
 *
 * Top element becomes the last element, every other element moves up by one.
 * This operation effectively moves the stack downwards. 
 */
void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	while (first->next)
		first = first->next;
	last = *stack;
	*stack = last->next;
	first->next = last;
	last->next = NULL;
}

/*
 * reverse_rotate - Rotates a stack upwards.
 * @stack: The stack to be rotated.
 *
 * The last element becomes top, every other element moves down by one.
 * This operation effectively moves the stack upwards.
 */
void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last)
		second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}
