#include <stdbool.h>
#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * bitonic_compare - It is helper to bitonic_merge,
 * sorts content of current subarray.
 *
 * @up: If true, sort in ascending order, false,
 * sort in descending order.
 * @x: It is subarray in current flame of recursion.
 * @size: The number of elements in 'x'.
 */
void bitonic_compare(bool up, int *x, size_t size)
{
	size_t dist, k;
	int tmp;

	dist = size / 2;
	for (k = 0; k < dist; k++)
	{
		if ((x[k] > x[k + dist]) == up)
		{
			tmp = x[k];
			x[k] = x[k + dist];
			x[k + dist] = tmp;
		}
	}
}
/**
 * bitonic_merge - The second recursive function of
 * bitionic_sort, sorts subarrays through bitionic_compare,
 * and merges the sorted results.
 *
 * @up: If true, sorts in ascending order, false,
 * descending order.
 * @x: It is subarray in previous frame of recursion.
 * @size: The number of elements in 'x'.
 * @orig_size: The number of elements in source array
 * being sorted.
 */
void bitonic_merge(bool up, int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size > 1)
	{
		first = x;
		second = x + (size / 2);
		bitonic_compare(up, x, size);
		bitonic_merge(up, first, size / 2, orig_size);
		bitonic_merge(up, second, size / 2, orig_size);
	}
}
/**
 * bitonic_sort_r - It is first recursive engine of
 * bitonic_sort, divides array into a binary tree of
 * subarrays and assigns sorting order.
 *
 * @up: If true, sorting is ascending order, false,
 * descending order.
 * @x: The subarray in previous frame of recursion.
 * @size: The number of elements in 'x'.
 * @orig_size: The number of elements in source array
 * being sorted.
 */
void bitonic_sort_r(bool up, int *x, size_t size, size_t orig_size)
{
	int *first, *second;

	if (size <= 1)
		return;
	first = x;
	second = x + (size / 2);
	printf("Merging [%llu/%llu] (%s):\n", size, orig_size,
			(up ? "UP" : "DOWN"));
	print_array(x, size);
	bitonic_sort_r(true, first, size / 2, orig_size);
	bitonic_sort_r(false, second, size / 2, orig_size);
	bitonic_merge(up, first, size, orig_size);
	printf("Result [%llu/%llu] (%s):\n", size, orig_size,
			(up ? "UP" : "DOWN"));
	print_array(x, size);
}
/**
 * bitonic_sort - The function sorts array of integers
 * in ascending order using bitonic sort algorithm.
 *
 * @array: The array of values to be printed.
 * @size: The number of elements in array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	bitonic_sort_r(true, array, size, size);
}
