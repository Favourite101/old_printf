#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NOTUSED(x) (void)(x)
#define SIZE 1024


#define FSUB 1
#define FADD 2
#define FZERO 4
#define FHASH 8
#define FSPACE 16

#define LONG 2
#define SHORT 1

/**
 * struct ft - struct
 * @ft: format
 * @fn: function
 */
struct ft
{
	char ft;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct ft ft_t - struct
 * @ft: format
 * @ft_t: function
 */
typedef struct ft ft_t;

int _printf(const char *format, ...);
int handler(const char *ft, int *i,
va_list list, char buff[], int flags, int width, int precision, int size);

int p_char(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_string(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_percent(va_list types, char buff[],
	int flags, int width, int precision, int size);

int p_int(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_binary(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_unsigned(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_octal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_hexadecimal(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_hexa_upper(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_hexa(va_list types, char map_to[],
char buff[], int flags, char flag_ch, int width, int precision, int size);

int p_non_printable(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_pointer(va_list types, char buff[],
	int flags, int width, int precision, int size);

int flags(const char *format, int *i);
int width(const char *format, int *i, va_list list);
int precision(const char *format, int *i, va_list list);
int size(const char *format, int *i);

int p_reverse(va_list types, char buff[],
	int flags, int width, int precision, int size);
int p_rot13string(va_list types, char buff[],
	int flags, int width, int precision, int size);

int handler_char(char c, char buff[],
	int flags, int width, int precision, int size);
int w_numb(int is_positive, int ind, char buff[],
	int flags, int width, int precision, int size);
int w_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int w_p(char buff[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int w_u(int is_negative, int ind,
char buff[],
	int flags, int width, int precision, int size);

int can_print(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int con_szn(long int num, int size);
long int con_szu(unsigned long int num, int size);

#endif /*MAIN_H*/
