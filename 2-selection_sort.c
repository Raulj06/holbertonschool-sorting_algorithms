#include "sort.h"
1
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: pointer to the first element of the array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	unsigned int i, n, min = 0;
	int tmp = 0;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (n = i + 1; n < size; n++)
		{
			if (array[j] < array[min])
				min = n;
		}

		if (min != i)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
