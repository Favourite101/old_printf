#include "main.h"

/**
 * p_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int p_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = SIZE - 2, length = 2, padd_start = 1; 
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	NOTUSED(width);
	NOTUSED(size);
	if (addrs == NULL)
		return (write(1, "(nil)", 5));
	buffer[SIZE - 1] = '\0';
	NOTUSED(precision);
	num_addrs = (unsigned long)addrs;
	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}
	if ((flags & FZERO) && !(flags & FSUB))
		padd = '0';
	if (flags & FADD)
		extra_c = '+', length++;
	else if (flags & FSPACE)
		extra_c = ' ', length++;
	ind++;

	
	return (w_p(buffer, ind, length,
				width, flags, padd, extra_c, padd_start));
}


/**
 * p_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int p_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		if (can_print(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buffer, i + offset);
		i++;
	}
	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}


/**
 * p_reverse - Prints reverse strings
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */

int p_reverse(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(size);
	str = va_arg(types, char *);
	if (str == NULL)
	{
		NOTUSED(precision);
		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

/**
 * p_rot13string - Print a string in rot13.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 *
 * Return: Numbers of chars printed
 */
int p_rot13string(va_list types, char buffer[],
			int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
}
