#include "sort.h"

/**
 * quick_sort_aux - quick sort auxiliary function
 * @array: array to apply quick sort
 * @low: index of the first elemen
 * @high: index of the last element
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort_aux(int *array, int low, int high, size_t size)
{
	int pivot, cur_pos, i;
	int tmp;

	if (low < high)
	{
		pivot = high;
		cur_pos = low;

		for (i = low; i < high; i++)
		{
			if (array[i] < array[pivot])
			{

				if (i != cur_pos)
				{
					tmp = array[i];
					array[i] = array[cur_pos];
					array[cur_pos] = tmp;
					print_array(array, size);
				}
				cur_pos++;
			}
		}
		if (cur_pos != pivot && array[cur_pos] != array[pivot])
		{
			tmp = array[cur_pos];
			array[cur_pos] = array[pivot];
			array[pivot] = tmp;
			print_array(array, size);
		}
		quick_sort_aux(array, low, cur_pos - 1, size);
		quick_sort_aux(array, cur_pos + 1, high, size);
	}

}
/**
 * quick_sort - quick sort algorthm
 * @array: array
 * @size: size of array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		quick_sort_aux(array, 0, size - 1, size);
}
