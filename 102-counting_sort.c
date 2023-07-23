#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - The function sorts an array of integers in
 * ascending order using a counting sort algorithm
 *
 * @array: The array of integers to be sorted
 * @size: The amount of elements in array
 */
void counting_sort(int *array, size_t size)
{
	int j, total, max;
	int *count, *output;

	if (!array || size < 2)
		return;

	max = array[0];
	for (j = 0; j < (int)size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;
	for (j = 0; j < (int)size; j++)
		count[array[j]]++;

	for (j = 0, total = 0; j < max + 1; j++)
	{
		total = count[j] + total;
		count[j] = total;
	}
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (j = 0; j < (int)size; j++)
	{
		output[count[array[j]] - 1] = array[j];
		count[array[j]]--;/*handling identical values*/
	}

	for (j = 0; j < (int)size; j++)
		array[j] = output[j];
	free(count);
	free(output);
}
