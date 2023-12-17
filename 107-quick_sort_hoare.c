#include "sort.h"

/**
 * hoare_partition - Partition an array using the Hoare partition scheme.
 *
 * @array: Input array to be partitioned.
 * @low: Index of the lowest element in the current partition.
 * @high: Index of the highest element in the current partition.
 * @size: Size of the array.
 *
 * Return: The partition index.
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	int x = low - 1;
	int y = high + 1;
	int temp;

	while (1)
	{
		/* Find the first element from the left greater than or = the pivot */
		do {
			x++;
		} while (array[x] < pivot);

		/* Find first element from the right smaller than or = the pivot. */
		do {
			y--;
		} while (array[y] > pivot);

		/*If left pointer is >= to right pointer, the partition is complete.*/
		if (x > y)
			return (y);

		/* Swap the elements at x and y. */
		temp = array[x];
		array[x] = array[y];
		array[y] = temp;
		print_array(array, size);
	}
}

/**
 * quicksort - Sort an array using the Quick Sort algorithm.
 *
 * @array: Input array to be sorted.
 * @low: Index of the lowest element in the current partition.
 * @high: Index of the highest element in the current partition.
 * @size: Size of the array.
 */
void quicksort(int *array, int low, int high, size_t size)
{

	int p;

	if (low < high)
	{
		/* Partition the array using Hoare's partition scheme. */
		p = hoare_partition(array, low, high, size);
		/* sort the two partitions recursively. */
		quicksort(array, low, p, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sort an array using the Quick Sort algorithm
 * with Hoare's partition.
 *
 * @array: Input array to be sorted.
 * @size: Size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	unsigned int low = 0;
	unsigned int high = size - 1;

	/* Check for NULL array or small size (already sorted). */
	if (array == NULL || size < 2)
		return;
	/* start the quick sort process. */
	quicksort(array, low, high, size);
}
