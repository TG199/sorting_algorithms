#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: array
 * @size: size of array
 *
 * Return: No return
 */
void counting_sort(int *array, size_t size)
{
	int max, m;
	int *count, *a;

	if (size < 2)
		return;
	max = 0;
	for (max = m = 0; m < (int)size; m++)
	{
		if (array[m] > max)
			max = array[m];
	}

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	for (m = 0; m <= max; m++)
		count[m] = 0;

	for (m = 0; m < (int)size; m++)
		count[array[m]] += 1;

	for (m = 1; m <= max; m++)
		count[m] += count[m - 1];

	print_array(count, (max + 1));
	a = malloc(sizeof(int) * size + 1);

	if (a == NULL)
		return;

	for (m = 0; m < (int)size; m++)
		array[m] = a[m];

	free(count);
	free(a);
}
