#include "main.h"

/**
 * handle_write_char - Prints a string
 * @c: char
 * @buff: buff
 * @flags:  flags.
 * @width: width.
 * @precision: precision
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int handler_char(char c, char buff[],
        int flags, int width, int precision, int size)
{
        int i = 0;
        char padd = ' ';
        NOTUSED(precision);
        NOTUSED(size);
        if (flags & FZERO)
            padd = '0';
        buff[i++] = c;
        buff[i] = '\0';
        if (width > 1)
        {
                buff[SIZE - 1] = '\0';
                for (i = 0; i < width - 1; i++)
                        buff[SIZE - i - 2] = padd;
                if (flags & FSUB)
                        return (write(1, &buff[0], 1) +
                                        write(1, &buff[SIZE - i - 1], width - 1));
                else
                    return (write(1, &buff[SIZE - i - 1], width - 1) +
                                        write(1, &buff[0], 1));
        }
        return (write(1, &buff[0], 1));
}

/**
 * write_number - Prints a string
 * @is_negative: Lista of arguments
 * @ind: char types.
 * @buff: buff array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int w_numb(int is_negative, int ind, char buff[],
        int flags, int width, int precision, int size)
{
        int length = SIZE - ind - 1;
        char padd = ' ', extra_ch = 0;

        NOTUSED(size);
        if ((flags & FZERO) && !(flags & FSUB))
                padd = '0';
        if (is_negative)
            extra_ch = '-';
        else if (flags & FADD)
            extra_ch = '+';
        else if (flags & FSPACE)
            extra_ch = ' ';

        return (w_num(ind, buff, flags, width, precision,
            length, padd, extra_ch));
}

/**
 * write_num - Write a number using a bufffer
 * @ind: Index at which the number starts on the buff
 * @buff: buff
 * @flags: Flags
 * @width: width
 * @prec: Precision specifier
 * @length: Number length
 * @padd: Pading char
 * @extra_c: Extra char
 *
 * Return: Number of printed chars.
 */
int w_num(int ind, char buff[],
        int flags, int width, int prec,
        int length, char padd, char extra_c)
{
        int i, padd_start = 1;
        if (prec == 0 && ind == SIZE - 2 && buff[ind] == '0' && width == 0)
                return (0);
        if (prec == 0 && ind == SIZE - 2 && buff[ind] == '0')
                buff[ind] = padd = ' ';
        if (prec > 0 && prec < length)
                padd = ' ';
        while (prec > length)
            buff[--ind] = '0', length++;
        if (extra_c != 0)
            length++;
        if (width > length)
        {
            for (i = 1; i < width - length + 1; i++)
            {
                 buff[i] = padd;
            }                           
                buff[i] = '\0';
                if (flags & FSUB && padd == ' ')
                {
                    if (extra_c)
                        buff[--ind] = extra_c;
                    return (write(1, &buff[ind], length) + write(1, &buff[1], i - 1));
                }
                else if (!(flags & FSUB) && padd == ' ')
                {
                    if (extra_c)
                        buff[--ind] = extra_c;
                    return (write(1, &buff[1], i - 1) + write(1, &buff[ind], length));
                }
                else if (!(flags & FSUB) && padd == '0')
                {
                    if (extra_c)
                        buff[--padd_start] = extra_c;

                    return (write(1, &buff[padd_start], i - padd_start) + 
                    write(1, &buff[ind], length - (1 - padd_start)));
                }
        }
        if (extra_c)
                buff[--ind] = extra_c;
        return (write(1, &buff[ind], length));
}

/**
 * write_unsgnd - Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buff
 * @buff: Array of chars
 * @flags: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 *
 * Return: Number of written chars.
 */
int w_u(int is_negative, int ind,
        char buff[],
        int flags, int width, int precision, int size)
{
        int length = SIZE - ind - 1, i = 0;
        char padd = ' ';

        NOTUSED(is_negative);
        NOTUSED(size);

        if (precision == 0 && ind == SIZE - 2 && buff[ind] == '0')
                return (0);
        if (precision > 0 && precision < length)
                padd = ' ';
        while (precision > length)
        {
                buff[--ind] = '0';
                length++;
        }
        if ((flags & FZERO) && !(flags & FSUB))
                padd = '0';
        if (width > length)
        {
                for (i = 0; i < width - length; i++)
                        buff[i] = padd;
                buff[i] = '\0';
                if (flags & FSUB)
                {
                        return (write(1, &buff[ind], length) + write(1, &buff[0], i));
                }
                else
                {
                        return (write(1, &buff[0], i) + write(1, &buff[ind], length));
                }
        }
        return (write(1, &buff[ind], length));
}

/**
 * write_pointer - Write a memory address
 * @buff: Arrays of chars
 * @ind: Index at which the number starts in the buff
 * @length: Length of number
 * @width: Width specifier
 * @flags: Flags specifier
 * @padd: Char representing the padding
 * @extra_c: Char representing extra char
 * @padd_start: Index at which padding should start
 *
 * Return: Number of written chars.
 */
int w_p(char buff[], int ind, int length,
        int width, int flags, char padd, char extra_c, int padd_start)
{
        int i;

        if (width > length)
        {
                for (i = 3; i < width - length + 3; i++)
                        buff[i] = padd;
                buff[i] = '\0';
                if (flags & FSUB && padd == ' ')
                {
                        buff[--ind] = 'x';
                        buff[--ind] = '0';
                        if (extra_c)
                                buff[--ind] = extra_c;
                        return (write(1, &buff[ind], length) + write(1, &buff[3], i - 3));
                }
                else if (!(flags & FSUB) && padd == ' ')
                {
                        buff[--ind] = 'x';
                        buff[--ind] = '0';
                        if (extra_c)
                                buff[--ind] = extra_c;
                        return (write(1, &buff[3], i - 3) + write(1, &buff[ind], length));
                }
                else if (!(flags & FSUB) && padd == '0')
                {
                        if (extra_c)
                                buff[--padd_start] = extra_c;
                        buff[1] = '0';
                        buff[2] = 'x';
                        return (write(1, &buff[padd_start], i - padd_start) +
                                write(1, &buff[ind], length - (1 - padd_start) - 2));
                }
        }
        buff[--ind] = 'x';
        buff[--ind] = '0';
        if (extra_c)
                buff[--ind] = extra_c;
        return (write(1, &buff[ind], SIZE - ind - 1));
}
