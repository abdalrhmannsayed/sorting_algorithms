#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order using the Quick
 *              sort algorithm and the Lomuto partition scheme
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - sorts a partition of an array of integers in ascending
 *                     order using the Quick sort algorithm and the Lomuto
 *                     partition scheme
 * @array: the array to sort
 * @lo: the index of the first element in the partition
 * @hi: the index of the last element in the partition
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, lo, hi, size);
		quick_sort_helper(array, lo, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, hi, size);
	}
}

/**
 * lomuto_partition - partitions an array of integers using the Lomuto
 *                    partition scheme
 * @array: the array to partition
 * @lo: the index of the first element in the partition
 * @hi: the index of the last element in the partition
 * @size: the size of the array
 *
 * Return: the index of the pivot element
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1, j, temp;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[hi])
	{
		temp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
