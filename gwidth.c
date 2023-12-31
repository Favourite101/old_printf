#include "main.h"

/**
 * width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */

int width(const char *format, int *i, va_list list)
{
	int curr_i;
	int widths = 0;

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		if (is_digit(format[curr_i]))
		{
			widths *= 10;
			widths += format[curr_i] - '0';
		}

		else if (format[curr_i] == '*')
		{
			curr_i++;
			widths = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = curr_i - 1;

	return (widths);
}
