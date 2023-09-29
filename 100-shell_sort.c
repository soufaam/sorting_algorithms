#include "sort.h"

/**
 * shell_sort - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: the size of array
 * Return: success
 */

void shell_sort(int *array, size_t size)
{
	int swap;
	size_t i = 0, j = size, k, l, val;

	val = 3 * j + 1;
	while (val >= size)
	{
		val = 3 * j + 1;
		j--;
	}
	val = 3 * j + 1;
	while (i < size && val >= 1)
	{
		for (k = val; k < size; k++)
		{
			swap = array[k];
			l = k;
			while (l >= val && array[l - val] > swap)
			{
				array[l] = array[l - val];
				l -= val;
				array[l] = swap;
			}
		}
		i++;
		j--;
		print_array(array, size);
		if (val == 1)
		break;
		val = 3 * j + 1;
	}
}
