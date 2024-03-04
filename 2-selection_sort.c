#include "sort.h"

/**
 * selection_sort - selection sort algorithm
 * @array: array
 * @size: size of array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t temp, i, j, imin;

	for (i = 0; i < size; i++)
	{
		imin = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[imin])
			{
				imin = j;
			}
		}
		if (i != imin)
		{
			temp = array[imin];
			array[imin] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
