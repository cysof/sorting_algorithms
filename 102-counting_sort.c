#include "sort.h"
/**
 * counting_sort - sorting array of ints
 * @array: array of ints
 * @size: size of array
 *
 */
void counting_sort(int *array, size_t size)
{
	int *copy, *counting;
	unsigned int max_value, i, temp;

	if (array == NULL || size < 2)
		return;

	i = 0;
	max_value = 0;
	while (i < size)
	{
		if (array[i] > (int)max_value)
			max_value = array[i];
		i++;
	}
	max_value++;

	counting = malloc(max_value * sizeof(int));
	if (counting == NULL)
		return;
	copy = malloc(size * sizeof(int));
	if (copy == NULL)
	{
		free(counting);
		return;
	}

	i = 0;
	while (i < size)
	{
		copy[i] = array[i];
		i++;
	}

	i = 0;
	while (i < max_value)
	{
		counting[i] = 0;
		i++;
	}

	i = 0;
	while (i < size)
	{
		counting[array[i]]++;
		i++;
	}

	i = 1;
	while (i < max_value)
	{
		counting[i] += counting[i - 1];
		i++;
	}

	print_array(counting, max_value);

	i = 0;
	while (i < size)
	{
		temp = copy[i];
		array[counting[temp] - 1] = temp;
		counting[temp]--;
		i++;
	}
	free(counting);
	free(copy);
}
