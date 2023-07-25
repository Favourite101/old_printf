#include "main.h"

/**
 * handler - Prints an argument based on its type
 * @ft: string
 * @list: argument list
 * @index: index
 * @buffer: buffer
 * @flags: active flags
 * @width: get width
 * @precision: precision
 * @size: size
 * Return: 1 or 2;
 */

int handler(const char *ft, int *index, va_list list, char buffer[],
        int flags, int width, int precision, int size)
{
        int i, unknown = 0, printedd = -1;
        ft_t ft_types[] = {
                {'c', p_char}, {'s', p_string}, {'%', p_percent},
                {'i', p_int}, {'d', p_int}, {'b', p_binary},
                {'u', p_unsigned}, {'o', p_octal}, {'x', p_hexadecimal},
                {'X', p_hexa_upper}, {'p', p_pointer}, {'S', p_non_printable},
                {'r', p_reverse}, {'R', p_rot13string}, {'\0', NULL}
        };
        for (i = 0; ft_types[i].ft != '\0'; i++)
                if (ft[*index] == ft_types[i].ft)
                        return (ft_types[i].fn(list, buffer, flags, width, precision, size));
        if (ft_types[i].ft == '\0')
        {
                if (ft[*index] == '\0')
                        return (-1);
                unknown += write(1, "%%", 1);
                if (ft[*index - 1] == ' ')
                        unknown += write(1, " ", 1);
                else if (width)
                {
                        --(*index);
                        while (ft[*index] != ' ' && ft[*index] != '%')
                                --(*index);
                        if (ft[*index] == ' ')
                                --(*index);
                        return (1);
                }
                unknown += write(1, &ft[*index], 1);
                return (unknown);
        }
        return (printedd);
}
