#include "main.h"

/**
 * size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */

int size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int sizes = 0;

	if (format[curr_i] == 'l')
		sizes = LONG;
	else if (format[curr_i] == 'h')
		sizes = SHORT;
	if (sizes == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;
	return (sizes);
}
