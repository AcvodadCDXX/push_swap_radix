/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3quicksort_dupcheck.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbogdano <bbogdano@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:35 by bbogdano          #+#    #+#             */
/*   Updated: 2024/03/21 12:33:28 by bbogdano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * qs_swap - Swaps the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 *
 * This function swaps the values pointed to by 'a' and 'b'. It's a utility
 * function used by the quick sort algorithm to rearrange elements in the array.
 */

static void	qs_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * partition - Partitions the array for the quick sort algorithm.
 * @arr: Array to be sorted.
 * @low: Starting index of the segment of the array to be sorted.
 * @high: Ending index of the segment of the array to be sorted.
 *
 * This function selects the last element in the segment as a pivot, then
 * rearranges the segment so that all elements less than or equal to the pivot
 * are on the left of the pivot, and all elements greater than the pivot are on
 * the right. It uses 'qs_swap' to perform the swapping of elements.
 * 
 * Return: The index of the pivot after partitioning.
 */

static int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = (low - 1);
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			qs_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	qs_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/*
 * quick_sort - Sorts an array using the quick sort algorithm.
 * @arr: Array to be sorted.
 * @low: Starting index of the array to be sorted.
 * @high: Ending index of the array to be sorted.
 *
 * This recursive function sorts an array by partitioning it into smaller
 * segments around a pivot element, then recursively sorting each segment.
 * It calls 'partition' to find the pivot's correct location and then
 * recursively sorts the segments to the left and right of the pivot.
 */

static void	quick_sort(int arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}

/*
 * has_duplicates - Checks for duplicate integers in a sorted array.
 * @arr: The sorted array of integers.
 * @size: The number of elements in the array.
 *
 * After sorting the array, this function checks for adjacent duplicate values.
 * It iterates through the sorted array, comparing each element with its
 * successor. Since the array is sorted, any duplicate values will be adjacent.
 * This method allows for an efficient check after sorting.
 *
 * Return: Returns 1 if duplicates are found, 0 otherwise.
 */
static int	has_duplicates(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	quicksort_dupcheck(int **sorted_array, const int *original, int size)
{
	*sorted_array = copy_array(original, size);
	if (*sorted_array == NULL)
		return (0);
	quick_sort(*sorted_array, 0, size - 1);
	if (has_duplicates(*sorted_array, size))
	{
		free(*sorted_array);
		*sorted_array = NULL;
		return (0);
	}
	return (1);
}
