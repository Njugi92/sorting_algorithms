#include "sort.h"
/**
 * shell_sort - Function sorts an array of integers in ascending
 * order using shell sort algorithm, with gap sizes determined by
 * a decreasing knuth sequence
 *
 * @array: An array of integers to be sorted
 * @size: The amount of elements in array
 */
void shell_sort(int *array, size_t size)
{
	int k, j, gap, n, knuth_max, tmp;

	if (!array || size < 2)
		return;

	n = (int)size;
	for (gap = 1; gap < n; gap = (gap * 3) + 1)
	{
		knuth_max = gap;
	}
	/*starts with largest knuth seq value less than n as gap*/
	/*work down seq to a gap of 1*/
	for (gap = knuth_max; gap > 0; gap = (gap - 1) / 3)
	{
		/*Do a gapped insertion sort for this gap size*/
		for (k = gap; k < n; k++)
		{
			/*add array[k] to gap sorted elements*/
			/*save array[k] in tmp preparing to overwrite*/
			tmp = array[k];
			/*shifting earlier gap sorted elements up until*/
			/*correct location for array[k] is found*/
			for (j = k; j >= gap && array[j - gap] > tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
	/*tmp original array[k] to its correct location*/
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
