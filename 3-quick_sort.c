#include "sort.h"

/**
 * swap -
**/

void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * partition -
**/

int partition(int *array, size_t size, int lo, int hi)
{
	int pivot = array[hi];
	
	int i = lo - 1;
	
	int j;
	
	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(array, i, j);
			print_array(array, size);
		}
	}
	swap(array, i + 1, hi);
	print_array(array, size);
	return (i+1);
}

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
	recursive_quick_sort(array, size, 0, size - 1);
}
