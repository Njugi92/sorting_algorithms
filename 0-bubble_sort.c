#include "sort.h"
/**
 * bubble_sort - The function sorts array elements
 * from min to max value
 *
 * @array: The array of elements
 * @size: The array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, n;
	int temp;
	bool swapped = true;

	if (!array || size < 2)
		return;

	n = size;
	while (swapped)
	{
		swapped = false;
		for (j = 1; j < n; j++)
		{
			if (array[j - 1] > array[j])
			{
				temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
				swapped = true;
				print_array(array, size);
			}
		}
		n--;
	}
}
