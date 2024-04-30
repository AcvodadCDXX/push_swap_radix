/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.5check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:19:29 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/30 14:43:38 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	int	i;

	i = stack_a->index;
	while (stack_a)
	{
		if (i > stack_a->index)
			return (0);
		i = stack_a->index;
		stack_a = stack_a->next;
	}
	return (1);
}
