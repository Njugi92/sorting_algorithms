#include "sort.h"
/**
 * swap - It is the position of two elements into
 * an array
 * @array: the array
 * @item1: An array element
 * @item2: an array element
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * hoare_partition - hoare partition sorting scheme
 * @array: The array to sort
 * @first: The first element of array
 * @last: The last element of array
 * @size: the size of the array
 * Return: returns the last position of the array sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pivot = array[last];

	while(1)
	{
		do {
			current++;
		} while (array[current] < pivot);
		do {
			finder--;
		} while (array[finder] > pivot);
		if (current >= finder)
			return (current);
		swap(array, current, finder);
		print_array(array, size);
	}
}
/**
 * qs - The quicksort algorithm implimentation
 * @array: the array
 * @first: the first array element
 * @last: the last element of array
 * @size: array size
 */
void qs(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t position = 0;

	if (first < last)
	{
		position = hoare_partition(array, first, last, size);
		qs(array, first, position - 1, size);
		qs(array, position, last, size);
	}
}
/**
 * quick_sort_hoare - function to prepare quicksort algorithm
 * @array: array to sort
 * @size: the array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
