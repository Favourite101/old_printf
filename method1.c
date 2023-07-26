#include "main.h"

/**
 * p_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buff: array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */

int p_unsigned(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		int i = SIZE - 2;

		unsigned long int num = va_arg(types, unsigned long int);

		num = con_szu(num, size);

		if (num == 0)
			buff[i--] = '0';

		buff[SIZE - 1] = '\0';

		while (num > 0)
		{
			buff[i--] = (num % 10) + '0';
			num /= 10;
		}
		i++;
	return (w_u(0, i, buff, flags, width, precision, size));
}

/**
 * p_octal - Prints an unsigned number in octal notation
 * @types: Lists of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int p_octal(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		int i = SIZE - 2;

		unsigned long int num = va_arg(types, unsigned long int);
		unsigned long int init_num = num;

		NOTUSED(width);

		num = con_szu(num, size);

		if (num == 0)
			buff[i--] = '0';

		buff[SIZE - 1] = '\0';

		while (num > 0)
		{
			buff[i--] = (num % 8) + '0';
			num /= 8;
		}
		if (flags & FHASH && init_num != 0)
		{
			buff[i--] = '0';
		}
		i++;
		return (w_u(0, i, buff, flags, width, precision, size));
}

/**
 * p_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lists of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int p_hexadecimal(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		return (p_hexa(types, "0123456789abcdef", buff,
				flags, 'x', width, precision, size));
}

/**
 * p_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lists of arguments
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int p_hexa_upper(va_list types, char buff[],
		int flags, int width, int precision, int size)
{
		return (p_hexa(types, "0123456789ABCDEF", buff,
				flags, 'X', width, precision, size));
}
/**
 * p_hexa - Prints a hexadecimal number
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buff: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int p_hexa(va_list types, char map_to[], char buff[],
		int flags, char flag_ch, int width, int precision, int size)
{
		int i = SIZE - 2;

		unsigned long int num = va_arg(types, unsigned long int);
		unsigned long int init_num = num;

		NOTUSED(width);

		num = con_szu(num, size);

		if (num == 0)
			buff[i--] = '0';

		buff[SIZE - 1] = '\0';

		while (num > 0)
		{
			buff[i--] = map_to[num % 16];
			num /= 16;
		}
		if (flags & FHASH && init_num != 0)
		{
			buff[i--] = flag_ch;
			buff[i--] = '0';
		}
		i++;

return (w_u(0, i, buff, flags, width, precision, size));
}
