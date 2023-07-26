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
	int i, count, printedd = 0, precisions, sizes, flag, widths, index = 0;
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
			printbuff(buff, &index);
			precisions = precision(format, &i, list);
			sizes = size(format, &i);
			flag = flags(format, &i);
			widths = width(format, &i, list);
			i++;
			count = handler(format, &i, list, buff, flag, widths, precisions, sizes);
			if (count == -1)
				return (-1);
			printedd += count;
		}
		else
		{
			buff[index++] = format[i];
			if (index == SIZE)
				printbuff(buff, &index);
			printedd++;
		}
	}
	printbuff(buff, &index);
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
