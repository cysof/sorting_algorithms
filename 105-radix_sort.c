#include "sort.h"

/**
 * get_max - Find the maximum value/number in an array.
 *
 * @array: The array of integers.
 * @size: The size of array.
 * Return: The maximum value.
 */
int get_max(int *array, size_t size)
{
	unsigned int i = 0;
	int max = 0;

	while (i < size)
	{
		if (array[i] > (int)max)
			max = array[i];
		i++;
	}
	return (max);
}


/**
 * count_sort - counting sort algorithm
 * @array: array of ints
 * @size: size of array
 * @pow: power of 10
 */
void count_sort(int *array, size_t size, int pow)
{
	int *copy;
	int counting[10];
	unsigned int i, temp;

	copy = malloc(size * sizeof(int));
	if (copy == NULL)
		return;

	i = 0;
	while (i < 10)
	{
		counting[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		counting[(array[i] / pow) % 10]++;
		i++;
	}

	i = 1;
	while (i < 10)
	{
		counting[i] += counting[i - 1];
		i++;
	}

	i = size - 1;
	while ((int)i >= 0)
	{
		temp = (array[i] / pow) % 10;
		copy[counting[temp] - 1] = array[i];
		counting[temp]--;
		i--;
	}
	i = 0;
	while (i < size)
	{
		array[i] = copy[i];
		i++;
	}
	free(copy);
}


/**
 * radix_sort - radix sorting algorithm
 * @array: array of ints
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
	int pow = 1;
	int max = get_max(array, size);

	if (array == NULL || size < 2)
		return;

	while (max / pow > 0)
	{
		count_sort(array, size, pow);
		print_array(array, size);
		pow = pow * 10;
	}
}
