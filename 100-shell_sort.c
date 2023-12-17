#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap using the Knuth sequence */
	gap = 1;
	while (gap < size / 3)
		gap = (gap * 3) + 1;

	while (gap)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];

			/* Insertion sort within the current gap */
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		/* Print the array after each decreasing interval */
		print_array(array, size);

		/* Decrease the gap according to the Knuth sequence */
		gap /= 3;
	}
}
