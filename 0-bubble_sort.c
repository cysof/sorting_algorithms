#include "sort.h"

/**
 * bubble_sort - this is a function that sort an array of int
 * using bubble sort
 *
 * @array: this is the array to be sorted
 * @size: This is the size of the array
 */
voidd bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int swapped, temp;

	if (array == NULL || size < 2)
		return;
	for (a = 0; a < size - 1; a++)
	{
		swapped = 0;
		for (b = 0; b < size - 1 - a; b++)
		{
			if (array[b] > array[b + 1])
				/*swap happens here*/
			{
				temp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		/* if no two elements were swaped in the passed */
		/* the array is already sorted. */

		if (!swapped)
		{
			break;
		}
	}
}

