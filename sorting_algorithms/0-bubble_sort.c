#include "sort.h"
/**
 * bubble_sort - Bubble Sort Algorithm
 * @array: array to sort
 * @size: size of the array
 * Description: A sort algorithm implemented using the bubble
 * sort algorithm
 */

void bubble_sort(int *array, size_t size)
{
	size_t j, i = size - 1;

	if (size < 2 || array == NULL)
		return;

	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] > array[j + 1])
			{
				array[j] ^= array[j + 1];
				array[j + 1] = array[j] ^ array[j + 1];
				array[j] ^= array[j + 1];
				print_array(array, size);
			}
			j++;
		}
		i--;
	}
}
