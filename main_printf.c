#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - function to produce output according to a format
 * *format: string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list input;
	long unsigned int i, count;

	va_start(input, format);
	for (i = 0; i <= sizeof(format) / sizeof(char); i++)
	{
		if (format[i] == '%')
		{
			i++;
			/*if (format[i+1] == 's')
			{
				printf(va_arg(input, char *));
				count++;
				continue;
			}
			else*/ if (format[i+1] == 'c')
			{
				putchar(va_arg(input, int));
				count++;
				continue;
			}
		}
		putchar(format[i]);
		count++;
	}
	va_end(input);

	return (count);
}
