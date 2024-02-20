#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sort.h"
/**
 * bubble_sort - function that sorts an array using bubble sort
 * @array: Array
 * @size: size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		bool swapped = false;

		for (b = 0; b < size - a - 1; b++)
		{
		if (array[b] > array[b + 1])
		{
			int temp = array[b];

			array[b] = array[b + 1];
			array[b + 1] = temp;
			swapped = true;
			print_array(array, size);
		}
		}
		if (!swapped)
			break;
	}
}
