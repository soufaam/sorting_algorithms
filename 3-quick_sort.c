#include "sort.h"


/**
 * partionate - Prints an array of integers
 *
 * @array: The array to be printed
 * @lo: Number of elements in @array
 * @hi: the size
 * Return: success
 */
size_t partionate(int *array, size_t lo, size_t hi)
{
	int pivot;
	size_t i, j, swap;

	i = lo - 1;
	printf("->%lu \n", hi);
	pivot = array[hi];
	for (j = lo ; j < hi + 1; j++)
	{
		if (array[j] < pivot)
		{
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
			i++;
			print_array(array, hi + 1);
		}
	}
	swap = array[i + 1];
	array[i + 1] = array[hi];
	array[hi] = swap;
	return (i + 1);
}

/**
 * _sort_quick - Prints an array of integers
 *
 * @array: The array to be printed
 * @lo: Number of elements in @array
 * @hi: the size
 * Return: success
 */

void _sort_quick(int *array, size_t lo, size_t hi)
{
	size_t part;

	if (lo < hi)
	{
		part = partionate(array, lo, hi);
		_sort_quick(array, lo, part - 1);
		_sort_quick(array, part + 1, hi);
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
	_sort_quick(array, 0, size - 1);
}
