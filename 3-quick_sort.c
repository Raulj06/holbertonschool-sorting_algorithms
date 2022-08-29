#include "sort.h"

/**
 * quick_sort - main calling function
 * @array: an array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: an array of integers
 * @lo: all of the elements in the array whose value is less
 * @hi: all of the elements in the array whose value is greater
 * @size: size of the array
 */
void quickSort(int *array, int lo, int hi, size_t size)
{
	int n;

	if (lo < hi)
	{
		n = partition(array, lo, hi, size);
		quickSort(array, lo, n - 1, size);
		quickSort(array, n + 1, hi, size);
	}

}

/**
 * partition - divides the array into two smaller arrays
 * @array: an array of integers
 * @lo: value is less
 * @hi: value is greater
 * @size: size of the array
 *
 * Return: the pivot point
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot;
	int i, n;

	pivot = array[hi];
	i = lo;

	for (n = lo; n < hi; n++)
	{
		if (array[n] < pivot)
		{
			swap(array, i, n, size);
			i++;
		}
	}
	swap(array, i, hi, size);
	return (i);
}

/**
 * swap - swaps two values in an array
 * @array: an array of integers
 * @i: first position in the array to be swapped
 * @j: second position in the array to be swapped
 * @size: size of the array
 */
void swap(int *array, int i, int n, size_t size)
{
	int temp;

	if (array[i] != array[n])
	{
		temp = array[i];
		array[i] = array[n];
		array[n] = temp;
		print_array(array, size);
	}
}
