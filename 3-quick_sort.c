#include "sort.h"


/**
 * partionate - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: Number of elements in @array
 * @end: the size
 * @size: the size of array
 * Return: success
 */
size_t partionate(int *array, size_t start, size_t end, size_t size)
{
	int pivot;
	size_t i, j, swap;

	i = start;
	pivot = array[end];
	for (j = start ; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			i++;
		}
	}
	swap = array[i];
	array[i] = pivot;
	array[end] = swap;
	print_array(array, size);
	printf(" -- > %lu \n", i);
	return (i);
}

/**
 * _sort_quick - Prints an array of integers
 *
 * @array: The array to be printed
 * @lo: Number of elements in @array
 * @hi: the size
 * @size: the size of array
 * Return: success
 */

void _sort_quick(int *array, size_t lo, size_t hi, size_t size)
{
	size_t part;

	if (lo < hi)
	{
	part = partionate(array, lo, hi, size);
	if (part)
		_sort_quick(array, lo, part - 1, size);
	_sort_quick(array, part + 1, hi, size);
	}
}
/**
 * quick_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	_sort_quick(array, 0, size - 1, size);
}
