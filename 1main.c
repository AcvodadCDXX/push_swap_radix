/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:43:57 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/30 14:47:23 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_arguments(int argc, char **argv, int **values, int *size)
{
	if (argc == 2)
		return (parse_single(argv[1], values, size));
	else
		return (parse_multiple(argc, argv, values, size));
}

static int	process_input(char **argv, int argc, t_stack **stack_a)
{
	int	*original;
	int	*sorted_array;
	int	size;

	original = NULL;
	sorted_array = NULL;
	size = 0;
	if (!parse_arguments(argc, argv, &original, &size))
		return (handle_error(original, NULL, NULL), 0);
	if (!quicksort_dupcheck(&sorted_array, original, size))
		return (handle_error(original, sorted_array, NULL), 0);
	if (!populate_stack_a(stack_a, original, sorted_array, size))
		return (handle_error(original, sorted_array, stack_a), 0);
	return (1);
}

static void	choose_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	count;

	count = get_stack_size(*stack_a);
	if (count == 2)
		sort_two(stack_a);
	else if (count == 3)
		sort_three(stack_a);
	else if (count == 4)
		sort_four(stack_a, stack_b);
	else if (count == 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b, count - 1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		status;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		status = process_input(argv, argc, &stack_a);
		if (!status)
		{
			free_stack(&stack_a);
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		if (!is_sorted(stack_a))
			choose_sort(&stack_a, &stack_b);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (EXIT_SUCCESS);
}
