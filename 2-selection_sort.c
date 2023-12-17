#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order using
 * the Selection Sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_int;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_int = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_int])
				min_int = j;
		}
		if (min_int != i)
		{
			/*swap the elements*/
			temp = array[i];
			array[i] = array[min_int];
			array[min_int] = temp;
			/* print the array after each swap */
			print_array(array, size);
		}
	}
}
