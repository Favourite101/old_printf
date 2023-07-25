#include "main.h"

/**
 * can_print - checks if a char is printable
 * @ca: Char to be evaluated
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int can_print(char ca)
{
        if (ca >= 32 && ca < 127)
                return (1);

        return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buff
 * @buff: buffer
 * @i: Index
 * @ascii: ASSCI CODE.
 *
 * Return: Always 3
 */
int append_hexa_code(char ascii, char buff[], int i)
{
        char inc[] = "0123456789ABCDEF";

        if (ascii < 0)
                ascii *= -1;
        buff[i++] = '\\';
        buff[i++] = 'x';
        buff[i++] = inc[ascii / 16];
        buff[i] = inc[ascii % 16];

        return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @c: char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
        if (c >= '0' && c <= '9')
                return (1);

        return (0);
}

/**
 * con_szn - Casts a number to the specified size
 * @num: Number
 * @size: size
 *
 * Return: Casted value of num
 */
long int con_szn(long int num, int size)
{
        if (size == S_LONG)
                return (num);
        else if (size == S_SHORT)
                return ((short)num);
        return ((int)num);
}

/**
 * con_szu - Casts a number to the specified size
 * @num: Number
 * @size: size
 *
 * Return: Casted value of num
 */
long int con_szu(unsigned long int num, int size)
{
        if (size == S_LONG)
                return (num);
        else if (size == S_SHORT)
                return ((unsigned short)num);

        return ((unsigned int)num);
}
