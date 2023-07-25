#include "main.h"

/**

 * precision - Calculates the precision for printing

 * @format: Formatted string in which to print the arguments

 * @i: List of arguments to be printed.

 * @list: list of arguments.

 *

 * Return: Precision.

 */

int precision(const char *format, int *i, va_list list)

{

        int curr_i = *i + 1;

        int precisions = -1;

        if (format[curr_i] != '.')

                return (precisions);

        precisions = 0;

        for (curr_i += 1; format[curr_i] != '\0'; curr_i++)

        {

                if (is_digit(format[curr_i]))

                {

                        precisions *= 10;

                        precisions += format[curr_i] - '0';

                }

                else if (format[curr_i] == '*')

                {

                        curr_i++;

                        precisions = va_arg(list, int);

                        break;

                }

                else

                        break;

        }

        *i = curr_i - 1;

        return (precisions);

}
