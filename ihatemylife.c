/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihatemylife.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:31:57 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/29 12:56:34 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_bits(int num)
{
	int	count;

	count = 0;
	while (num)
	{
		count++;
		num >>= 1;
	}
	return (count);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b, int max_val)
{
	int	max_bits;
	int	current_bit;
	int	i;
	int	num;

	max_bits = count_bits(max_val);
	current_bit = 0;
	while (current_bit < max_bits)
	{
		i = get_stack_size(*stack_a);
		while (i > 0)
		{
			num = (*stack_a)->index;
			if (((num >> current_bit) & 1) == 1)
				do_ra(stack_a);
			else
				do_pb(stack_a, stack_b);
			i--;
		}
		while (*stack_b != NULL)
			do_pa(stack_b, stack_a);
		current_bit++;
	}
}
