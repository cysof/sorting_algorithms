#include "sort.h"

/**
 * bitonic_compare - Compares and swaps two elements based on the direction.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_compare(int *array, size_t size, size_t low, size_t dir)
{
	size_t i, j;
	int temp;

	if (size > 1)
	{
		size_t half = size / 2;

		for (i = low; i < low + half; i++)
		{
			if ((array[i] > array[i + half]) == dir)
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
				printf("Result: ");
				for (j = 0; j < size; j++)
				{
					printf("%d", array[j]);
					if (j < size - 1)
					{
						printf(", ");
					}
				}
				printf("\n");
			}
		}

		bitonic_compare(array, half, low, dir);
		bitonic_compare(array, half, low + half, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @low: The starting index.
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 */
void bitonic_sort_recursive(int *array, size_t size, size_t low, size_t dir)
{
	if (size > 1)
	{
		size_t half = size / 2;

		bitonic_sort_recursive(array, half, low, 1);
		bitonic_sort_recursive(array + half, half, low, 0);

		bitonic_compare(array, size, low, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using Bitonic Sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}

	bitonic_sort_recursive(array, size, 0, 1);
}

/* Definitely not implemented correctly, need to revisit */
