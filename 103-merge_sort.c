#include "sort.h"

/**
 * print_parts - Prints part of the list.
 *
 * @array: Input array.
 * @min: Start of array.
 * @max: End of array.
 */
void print_parts(int *array, size_t min, size_t max)
{
	size_t i;

	for (i = min; i < max; i++)
	{
		if (i > min)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * top_down - Merge using the top-down method.
 * @A: Original input of array.
 * @B: Temporary array for merging.
 * @min: Start of array.
 * @mid: Middle of the array.
 * @max: End of array.
 */
void top_down(int *A, int *B, size_t min, size_t mid, size_t max)
{
	size_t i = min, j = mid, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_parts(A, min, mid);
	printf("[right]: ");
	print_parts(A, mid, max);
	for (k = min; k < max; k++)
	{
		if (i < mid && (j >= max || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_parts(B, min, max);
	for (k = min; k < max; k++)
		A[k] = B[k];
}

/**
 * top_down_split - Split the array into two parts.
 * @A: Original input of array.
 * @B: Temporary array for merging.
 * @min: Start of array.
 * @max: End of array.
 */
void top_down_split(int *A, int *B, size_t min, size_t max)
{
	size_t mid;

	/* If the array has less than 2 elements, no need to split */
	if (max - min < 2)
		return;
	mid = (min + max) / 2;
	top_down_split(A, B, min, mid);
	top_down_split(A, B, mid, max);
	top_down(A, B, min, mid, max);
}

/**
 * merge_sort - Sort an array using the merge sort method.
 * @array: Input array.
 * @size: Size of the input array.
 */
void merge_sort(int *array, size_t size)
{
	int *newlist;

	/* Check for valid input and base case for recursion */
	if (array == NULL || size < 2)
		return;

	newlist = malloc(sizeof(int) * size);
	if (newlist == NULL)
		return;
	top_down_split(array, newlist, 0, size);
	free(newlist);
}
