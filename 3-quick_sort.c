#include "sort.h"

/**
 * swap - swaps i and j
 * @array: the array
 * @i: index 1
 * @j: index 2
**/

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition - partition the array
 * @array: the array
 * @size: size of the array
 * @lo: start of the index
 * @hi: end of the index
 * Return: partition index
**/

size_t partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
			print_array(array, size);
		}
	}

	if (array[hi] < array[i + 1])
	{
		swap(array, i + 1, hi);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursive_quick_sort - recursive
 * @array: the array
 * @size: size of the array
 * @lo: start of the index
 * @hi: end of the index
**/

void recursive_quick_sort(int *array, size_t size, int lo, int hi)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, size, lo, hi);
		recursive_quick_sort(array, size, lo, p - 1);
		recursive_quick_sort(array, size, p + 1, hi);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order,
 * using the Quick sort algorithm
 * @array: the array
 * @size: size of the array
**/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_quick_sort(array, size, 0, size - 1);
}
