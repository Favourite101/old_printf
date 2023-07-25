#include "main.h"

/**

 * get_flags - Calculates active flags

 * @format: Formatted string in which to print the arguments

 * @i: takes a parameter.

 * Return: Flags:

 */

int flags(const char *format, int *i)

{

        

        int j, curr_i;

        int flag = 0;

        const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

        const int FLAGS_ARR[] = {FSUB, FADD, FZERO, FHASH, FSPACE, 0};

        for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)

        {

                for (j = 0; FLAGS_CH[j] != '\0'; j++)

                        if (format[curr_i] == FLAGS_CH[j])

                        {

                                flag |= FLAGS_ARR[j];

                                break;

                        }

                if (FLAGS_CH[j] == 0)

                        break;

        }

        *i = curr_i - 1;

        return (flag);

}
