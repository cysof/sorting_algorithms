#include "sort.h"

/**
 * swap - Swaps two integers in an array.
 *
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Rearranges the array elements to form a max heap.
 *
 * @array: The array to be heapified.
 * @size: The size of the array.
 * @index: The index to start the heapify process.
 * @size_original: The original size of the array for printing.
 */
void heapify(int *array, size_t size, size_t index, size_t size_original)
{
	size_t largest, left, right;

	left = 2 * size_original + 1;
	right = 2 * size_original + 2;
	largest = size_original;

	if (left < index && array[left] > array[largest])
		largest = left;
	if (right < index && array[right] > array[largest])
		largest = right;

	if (largest != size_original)
	{
		swap(array + size_original, array + largest);
		print_array(array, size);
		heapify(array, size, index, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap Sort.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, array + i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
