#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
void quicksort(int *array, int low, int high, size_t size);
int partition(int *array, int low, int high, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void dll_adj_swap(listint_t **list, listint_t *left, listint_t *right);
listint_t *swap_node(listint_t *node, listint_t **list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void printArray(int *array, int iBeg, int iEnd);
void copyArray(int *source, int iBeg, int iEnd, int *dest);
void TopDownMerge(int *source, int iBeg, int iMid, int iEnd, int *dest);
void TopDownSplitMerge(int *source, int iBeg, int iEnd, int *dest);
void heap_sort(int *array, size_t size);
int iParent(int i);
int iLeftChild(int i);
void convertToHeap(int *array, size_t size);
void shiftDown(int *array, size_t size, int start, int end);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
