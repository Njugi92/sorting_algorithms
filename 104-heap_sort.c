#include "sort.h"
/**
 * iParent - This returns index of parent node for
 * an array arranged as a binary tree, for index i.
 *
 * @i: The starting index to determine parent node
 * index.
 * Return: The index of parent node.
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}
/**
 * iLeftChild - It returns index of left child
 * branch for an array arranged as a binary tree
 * for index i
 *
 * @i: Its starting index to determine left child
 * branch index.
 * Return: The index of left child node.
 */
int iLeftChild(int i)
{
	return ((2 * i) + 1);
}
/**
 * convertToHeap - This arranges array of integers
 * into a heap/binary scheme
 *
 * @array: The array of integers.
 * @size: The number of elements in array.
 */
void convertToHeap(int *array, size_t size)
{
	int start;

	start = iParent(size - 1);

	while (start >= 0)
	{
		shiftDown(array, size, start, size - 1);
		start--;
	}
}
/**
 * shiftDown - It shuffles heap/binary tree sorted array
 * sorted by ascending value.
 * @array: The array of values to be sorted in place,
 * from heap to ascending.
 * @size: The number of elements in array.
 * @start: Its starting index.
 * @end: The ending index.
 */
void shiftDown(int *array, size_t size, int start, int end)
{
	int root, swap, tmp, child;

	root = start;

	while (iLeftChild(root) <= end)
	{
		child = iLeftChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			tmp = array[root];
			array[root] = array[swap];
			array[swap] = tmp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}
/**
 * heap_sort - The function sorts array of integers in ascending
 * order using a shift-down algorithm.
 * @array: The array of values to be sorted.
 * @size: number of elements in array
 */
void heap_sort(int *array, size_t size)
{
	int iEnd, tmp;

	if (!array || size < 2)
		return;

	convertToHeap(array, size);

	iEnd = (int)size - 1;
	while (iEnd > 0)
	{
		tmp = array[iEnd];
		array[iEnd] = array[0];
		array[0] = tmp;
		print_array(array, size);
		iEnd--;
		shiftDown(array, size, 0, iEnd);
	}
}
