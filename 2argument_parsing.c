/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2argument_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:21:36 by bbogdano          #+#    #+#             */
/*   Updated: 2024/04/29 12:39:13 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * validate_and_convert - Validates and converts a string to an integer.
 * @str: The string to convert.
 * @converted_value: Pointer to an integer to store the converted value.
 *
 * This function checks if the given string represents a valid integer within
 * the INT_MIN and INT_MAX range. If valid, the converted integer is stored in
 * the location pointed to by converted_value. Returns 1 on success, or 0 if
 * the string does not represent a valid integer or is out of range.
 */

static int	validate_and_convert(const char *str, int *converted_value)
{
	long	value;

	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	*converted_value = (int)value;
	return (1);
}

/*
 * convert_strings_to_ints - Converts strings to integers and stores them.
 * @strs: Array of string pointers to convert.
 * @values: Pointer to the array to store converted integers.
 * @count: Number of strings to convert.
 *
 * Iterates over an array of strings, converting each to an integer and storing
 * the results in a dynamically allocated array. If any string cannot be
 * converted or is out of the integer range, it frees allocated memory and
 * returns 0. Returns 1 on successful conversion of all strings.
 */

static int	convert_strings_to_ints(char **strs, int **values, int count)
{
	int	i;
	int	valid;
	int	temp;

	*values = (int *)malloc(sizeof(int) * count);
	if (*values == NULL)
		return (0);
	i = 0;
	while (i < count)
	{
		valid = validate_and_convert(strs[i], &temp);
		if (!valid)
		{
			free(*values);
			return (0);
		}
		(*values)[i] = temp;
		i++;
	}
	return (1);
}

/*
 * count_strings - Counts the number of strings in a null-terminated array.
 * @strs: The null-terminated array of strings to count.
 *
 * Counts and returns the number of strings in a null-terminated string array,
 * not including the null terminator.
 */

static int	count_strings(char **strs)
{
	int	count;

	count = 0;
	while (strs[count] != NULL)
		count++;
	return (count);
}

/*
 * parse_single_argument - Parses a space-delimited string into integers.
 * @str: The input string containing space-delimited integers.
 * @values: Pointer to the array to store the parsed integers.
 * @size: Pointer to store the number of elements in the array.
 *
 * Splits a single space-delimited string into individual strings, then
 * converts and stores each as an integer in a dynamically allocated array.
 * Ensures all integers are within the valid range. On success, updates values
 * and size accordingly and returns 1. Returns 0 on failure, ensuring proper
 * cleanup and memory management.
 */

int	parse_single(char *str, int **values, int *size)
{
	char	**strs;
	int		count;

	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (0);
	count = count_strings(strs);
	if (!convert_strings_to_ints(strs, values, count))
	{
		ft_free_split(strs);
		return (0);
	}
	*size = count;
	ft_free_split(strs);
	return (1);
}

/*
 * parse_multiple_arguments - Parses command-line arguments into integers.
 * @argc: The number of command-line arguments.
 * @argv: The array of command-line arguments.
 * @values: Pointer to an array of integers to store the converted values.
 * @size: Pointer to store the number of elements in the array.
 *
 * Converts command-line arguments (excluding the program name) into an array
 * of integers, checking each argument for validity as an integer within the
 * allowable range. The function allocates memory for the integer array and
 * populates it with the converted values. In case of invalid input or memory
 * allocation failure, the function performs necessary cleanup and returns 0
 * to indicate failure. On successful conversion of all arguments, it returns 1.
 * foundation for further processing, such as sorting and index assignment.
 */
int	parse_multiple(int argc, char **argv, int **values, int *size)
{
	int	i;
	int	temp;
	int	valid;

	*size = argc - 1;
	*values = (int *)malloc(sizeof(int) * (*size));
	if (*values == NULL)
		return (0);
	i = 0;
	while (i < *size)
	{
		valid = validate_and_convert(argv[i + 1], &temp);
		if (!valid)
		{
			free(*values);
			return (0);
		}
		(*values)[i] = temp;
		i++;
	}
	return (1);
}
