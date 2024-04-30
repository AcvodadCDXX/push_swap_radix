/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8utility.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 14:45:21 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/30 16:13:14 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ft_free_split - Frees an array of strings.
 * @array: The array of strings to be freed.
 *
 * Iterates through an array of strings and frees each string, then frees
 * the array itself. This function is typically used to clean up after
 * calling ft_split. It checks if the array is NULL before attempting to
 * free it to prevent dereferencing a NULL pointer.
 */
void	ft_free_split(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

/*
 * ft_atol - Converts a string to a long integer.
 * @str: The string to be converted.
 *
 * Parses the given string, converting it to a long integer value. The function
 * skips leading whitespace, processes an optional sign ('+' or '-'), and
 * accumulates digits into a long integer until a non-digit character is
 * encountered or the end of the string is reached.
 *
 * Return: The converted long integer value. If no valid conversion can be
 * performed (e.g., the string does not start with digits or a sign followed
 * by digits), the function returns 0.
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

/*
 * copy_array - Duplicates an integer array.
 * @original: Original array to duplicate.
 * @size: Element count.
 *
 * Generates an unsorted array copy for index-value mapping. Used to 
 * associate unsorted positions with sorted indices for stack operations.
 * Return: New array copy named to_sort, or NULL on failure.
 */
int	*copy_array(const int *original, int size)
{
	int	*to_sort;
	int	i;

	to_sort = (int *)malloc(sizeof(int) * size);
	if (!to_sort)
		return (NULL);
	i = 0;
	while (i < size)
	{
		to_sort[i] = original[i];
		i++;
	}
	return (to_sort);
}

void	handle_error(int *values, int *sorted_values, t_stack **stack_a)
{
	if (values)
		free(values);
	if (sorted_values)
		free(sorted_values);
	if (stack_a && *stack_a)
		free_stack(stack_a);
	write(STDERR_FILENO, "Error\n", 6);
}
