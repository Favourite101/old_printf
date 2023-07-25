#include "main.h"

void printbuff(char buff[], int *buff_index);

/**
 * _printf - function to produce output according to a format
 * @format: string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i, count, printedd = 0, precision, size, flags, width, index = 0;
	char buff[SIZE];

	if (format == NULL)
	{
		return (-1);
	}
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			printbuff(buff, &buff_index);
			precision = precision(format, &i, list);
			size = size(format, &i);
			flags = flags(format, &i);
			width = width(format, &i, list);
			i++;
			count = handler(format, &i, list, buff, flags, width, precision, size);
			if (count == -1)
				return (-1);
			printedd += count;
		}
		else
		{
			buff[buff_index++] = format[i];
			if (buff_index == SIZE)
				printbuff(buff, &buff_index);
			printedd++;
		}
	}
	printbuff(buff, &buff_index);
	va_end(list);

	return (printedd);
}

/**
 * printbuff - prints a buffer
 * @buff: buffer to be printed
 * @buff_index: buffer index
 *
 * Return: nothing
 */
void printbuff(char buff[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buff[0], *buff_index);
	*buff_index = 0;
}
