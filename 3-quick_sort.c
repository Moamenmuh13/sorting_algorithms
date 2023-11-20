#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quick sort algorithm with lomuto partition scheme.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);

	print_array(array, size);
}
/**
 * quick_sort_recursive - Recursively sorts a partition of an array.
 * @array: The array to be sortd.
 * @low: the starting index of the partition to be sorted.
 * @high: the ending index of the partition to be sorted.
 * @size: the size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}
/**
 * lomuto_partition - Lomuto partition scheme for quick sort.
 * @array: The array to be sortd.
 * @low: the starting index of the partition to be sorted.
 * @high: the ending index of the partition to be sorted.
 * @size: the size of the array.
 *
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}
