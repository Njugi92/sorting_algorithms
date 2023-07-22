#include "sort.h"
/**
 * selection_sort - The function sorts an array of integers
 * using a selection sort algorithm
 * @array: The array of integers to be sorted
 * @size: The amount of elements in an array
 */
void selection_sort(int *array, size_t size)
{
	int k, j, min_j, tmp, n = (int)size;

	if (!array || size < 2)
		return;

	/*for every n-member position array*/
	for (k = 0; k < n - 1; k++)
	{
		/*scan from that position to end*/
		min_j = k;
		for (j = k + 1; j < n; j++)
		{
			/*the minimum value in that range*/
			if (array[j] < array[min_j])
			{
				min_j = j;
			}
		}
		/*if its lower than value at start of the range*/
		/*swap them*/
		if (min_j != k)
		{
			tmp = array[k];
			array[k] = array[min_j];
			array[min_j] = tmp;
			print_array(array, size);
		}
	}
}
