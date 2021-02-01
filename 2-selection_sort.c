#include "sort.h"
/**
* selection_sort - selection sort method.
* @array: unsorted array.
* @size: size of array.
*/
void selection_sort(int *array, size_t size)
{
	size_t c, i, position, swap;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		position = i;
		for (c = i + 1; c < size; c++)
		{
			if (array[position] > array[c])
			{
				position = c;
			}
		}
		if (position != i)
		{
			swap = array[position];
			array[position] = array[i];
			array[i] = swap;
			print_array(array, size);
		}
	}
}
