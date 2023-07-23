#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * printArray - The function prints array of integers for
 * range of indicies.
 *
 * @array: Its array of values to be printed.
 * @iBeg: The starting index value.
 * @iEnd: The ending index value.
 */
void printArray(int *array, int iBeg, int iEnd)
{
	int k;

	for (k = iBeg; k < iEnd; k++)
		if (k < iEnd - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
}
/**
 * copyArray - This is simply copying 1 to 1 from
 * sorce[] to destination[]
 *
 * @source: The array of values to be sorted.
 * @iBeg: The starting index value.
 * @iEnd: The ending index value.
 * @dest: The array to store sorted integers.
 */
void copyArray(int *source, int iBeg, int iEnd, int *dest)
{
	int k;

	for (k = iBeg; k < iEnd; k++)
		dest[k] = source[k];
}
/**
 * TopDownMerge - It sorts subsections ('runs') source[]
 * by ascending value
 *
 * @source: The array of values to be sorted.
 * @iBeg: The left run starting index value.
 * @iMid: The right run starting index value.
 * @iEnd: The right run ending index value.
 * @dest: The array to store sorted integers.
 */
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest)
{
	int k, j, l;

	k = iBeg, j = iMid;

	printf("Merging...\n");
	printf("[left]: ");
	printArray(source, iBeg, iMid);
	printf("[right]: ");
	printArray(source, iMid, iEnd);
	/*while there are elements in the right or left runs*/
	for (l = iBeg; l < iEnd; l++)
	{
		/*if left run head exists and is <= existing right run head*/
		if (k < iMid && (j >= iEnd || source[k] <= source[j]))
		{
			dest[l] = source[k];
			k++;
		}
		else
		{
			dest[l] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	printArray(dest, iBeg, iEnd);
}
/**
 * TopDownSplitMerge - Its recursive engine of merge sort,
 * splits working copy of array int left and right runs
 * then merges with TopDownMerge
 *
 * @source: The array of integer to be sorted.
 * @iBeg: The starting index value.
 * @iend: The ending index value.
 * @dest: The array to store sorted integers.
 */
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest)
{
	int iMid;

	if (iEnd - iBeg < 2)/*run size == 1*/
		return;/*its sorted*/
	/*split the run longer than one item into halves*/
	iMid = (iEnd + iBeg) / 2;

	TopDownSplitMerge(dest, iBeg, iMid, source);/*left run sort*/
	TopDownSplitMerge(dest, iMid, iEnd, source);/*right run sort*/
	/*merge resulting runs from array[] to work_copy[]*/
	TopDownMerge(source, iBeg, iMid, iEnd, dest);
}
/**
 * merge_sort - The function sorts an array of integers in
 * ascending order using a top-down merge sort algorithm.
 *
 * @array: The array of integers to be sorted.
 * @size: The amount of elements in array.
 */
void merge_sort(int *array, size_t size)
{
	int *work_copy;

	if (!array || size < 2)
		return;

	work_copy = malloc(sizeof(int) * size);
	if (!work_copy)
		return;

	copyArray(array, 0, size, work_copy);
	TopDownSplitMerge(work_copy, 0, size, array);

	free(work_copy);
}
