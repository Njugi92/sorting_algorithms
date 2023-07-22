#include "sort.h"
/**
 * partition - Function scans a partition of an array of integers
 * for values less than pivot value, and swaps them with the pivot
 * value in partition, then swaps pivot value with the first value
 * in partition.
 *
 * @array: The array of integers to be sorted
 * @low: The index in array that begins partition
 * @high: The index in array that ends partition
 * @size: The amount of elements in array
 * Return: new index at which to start new recursive partation
 */
int partition(int *array, int low, int high, size_t size)
{
	int k, j, pivot, tmp;

	pivot = array[high];
	k = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			tmp = array[k];
			array[k] = array[j];
			array[j] = tmp;
			if (array[k] != array[j])
				print_array(array, size);
			k++;
		}
	}
	tmp = array[k];
	array[k] = array[high];
	array[high] = tmp;
	if (array[k] != array[high])
		print_array(array, size);
	return (k);
}
/**
 * quicksort - The function recursively sorts an array of integers by
 * separating into two partitions, using lomuto quick sort algorithm
 *
 * @array: The array of integers to be sorted
 * @low: The index in the array that begins partition
 * @high: The index in array that ends the partition
 * @size: amount of elements in the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p - 1, size);
		quicksort(array, p + 1, high, size);
	}
}
/**
 * quick_sort - The function sorts an array of integers in ascending
 * order using a quick sort algorithm, with lomuto partition scheme.
 *
 * @array: The array of integers to be sorted.
 * @size: The amount of elements in array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, (int)size - 1, size);
}
