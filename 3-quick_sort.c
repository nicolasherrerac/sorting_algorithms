#include "sort.h"
/**
 * quick_sort - quick sort method.
 * @array: unsorted array.
 * @size: size of array.
 * Return: void.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1, size);
}
/**
 * sort - function to call recursive and create new pivots
 * @array: array to be sorted
 * @start: beginning of sorting array
 * @end: end of sorting array
 * @size: size of array
 * Return: void
 */
void sort(int *array, size_t start, size_t end, size_t size)
{
	size_t pivot;

	if (end == 0 || end <= start)
		return;
	pivot = partition(array, start, end, size);
	if (pivot != 0 && pivot > start)
		sort(array, start, pivot - 1, size);
	if (pivot < size - 1)
		sort(array, pivot + 1, end, size);
}
/**
 * partition - function to partition array according to pivot
 * @array: array to be partitioned
 * @start: beginning of comparison index
 * @pivot: partition index
 * @size: size of array
 * Return: void
 */
size_t partition(int *array, size_t start, size_t pivot, size_t size)
{
	size_t i;

	for (i = start; i < pivot; i++)
	{
		if (array[i] < array[pivot])
		{
			if (i != start)
			{
				swap(&array[start], &array[i]);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > array[pivot])
	{
		swap(&array[start], &array[pivot]);
		pivot = start;
		print_array(array, size);
	}
	return (pivot);
}
/**
 * swap - function to swap elements
 * @a: element 1
 * @b: element 2
 * Return: void
 */
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
