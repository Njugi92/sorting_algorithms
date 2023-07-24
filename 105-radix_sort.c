#include "sort.h"
#include <stdlib.h>
/**
 * init_bucket_count - It resets bucket_count to 0.
 * @bucket_count: The array containing the amount of members
 * for arrays in buckets.
 */
void init_bucket_count(int *bucket_count)
{
	int k;

	for (k = 0; k < 10; k++)
		bucket_count[k] = 0;
}
/**
 * build_buckets - It allocates space for arrays to be held
 * in 'buckets'.
 * @buckets: This is array of arrays each containing sorted
 * members of 'array'.
 * @bucket_count: The array containing amounts of members
 * for arrays in buckets.
 */
void build_buckets(int *bucket_count, int **buckets)
{
	int *bucket;
	int k;

	for (k = 0; k < 10; k++)
	{
		bucket = malloc(sizeof(int) * bucket_count[k]);
		if (!bucket)
		{
			for (; k > -1; k--)
				free(buckets[k]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[k] = bucket;
	}
	init_bucket_count(bucket_count);
}
/**
 * find_max - It searches array of integers for highest value.
 * @array: The array of values to be searched.
 * @size: The number of elements in array.
 * Return: The largest integer stored in array.
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t n;

	max = array[0];
	for (n = 1; n < size; n++)
		if (array[n] > max)
			max = array[n];
	return (max);
}
/**
 * into_array - It flattens buckets into array sorted by
 * current digit place, then prints results and frees current
 * buckets for next pass.
 *
 * @array: The array of values to be printed.
 * @size: It is number of elements in array.
 * @buckets: The array of arrays each containing sorted
 * members of 'array'
 * @bucket_count: The array containing the amount of members
 * for arrays in 'buckets'.
 */
void into_array(int *array, size_t size, int **buckets, int *bucket_count)
{
	int i, j, k;

	/*flatten bucket members in order into array sorted by place*/
	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < bucket_count[k]; j++, i++)
			array[i] = buckets[k][j];
	}
	/*print results*/
	print_array(array, size);
	/*free buckets from current pass*/
	for (i = 0; i < 10; i++)
		free(buckets[i]);
}
/**
 * radix_sort - It sorts array of integers in ascending order
 * using a radix sort algorithm, starting with LSD,and sorting
 * by next digit to left. Here size of buckets is determined
 * by max range of key variance(digits 0 - 9), for much large ranges
 * other solutions are needed.
 *
 * @array: The array of values to be sorted.
 * @size: The number of elements in array
 */
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucket_count[10];
	int max, max_digits, pass, divisor, digit;
	size_t n;

	if (!array || size < 2)
		return;
	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(1);
	/*amount of places in largest elements*/
	max = find_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;
	/*one sorting pass for each place in max_digits*/
	for (pass = 0, divisor = 1; pass < max_digits; pass++, divisor *= 10)
	{
		init_bucket_count(bucket_count);
		/*the amount of members in each bucket*/
		for (n = 0; n < size; n++)
		{
			digit = (array[n] / divisor) % 10;
			bucket_count[digit]++;
		}
		build_buckets(bucket_count, buckets);
		/*fill buckets sorting by digit at current power of 10*/
		for (n = 0; n < size; n++)
		{
			/*digit of source element at power of 10*/
			digit = (array[n] / divisor) % 10;
			/*place members of source array in digit's bucket*/
			buckets[digit][bucket_count[digit]] = array[n];
			/*record increase in bucket fill level*/
			bucket_count[digit]++;
		}
		into_array(array, size, buckets, bucket_count);
	}
	free(buckets);
}
