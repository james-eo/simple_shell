#include "shell.h"

/**
 * my_printf - custom printf implementation
 * @format: format string
 * @...: variable arguments
 */

void my_printf(const char *format, ...)
{
	const char *ptr;
	char *str_arg;
	int int_arg;
	va_list args;
	char buffer[1024];
	int buffer_index = 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			switch (*ptr)
			{
				case 'd':
					int_arg = va_arg(args, int);
					buffer_index += my_itoa(buffer + buffer_index, int_arg);
					break;
				case 's':
					str_arg = va_arg(args, char *);
					buffer_index += my_strcpy(buffer + buffer_index, str_arg);
					break;
				default:
					write(STDOUT_FILENO, "%", 1);
					write(STDOUT_FILENO, ptr, 1);
					break;
			}
		}
		else
		{
			buffer[buffer_index++] = *ptr;
		}
	}
	write(STDOUT_FILENO, buffer, buffer_index);
	va_end(args);
}

/**
 * my_itoa - converts an integer to a string
 * @buffer: the buffer to store the result
 * @num: the integer to convert
 * Return: the number of characters written to the buffer
 */

int my_itoa(char *buffer, int num)
{
	int count = 0;

	while (num != 0)
	{
		buffer[count++] = '0' + num % 10;
		num /= 10;
	}
	reverse_string(buffer, count);
	return (count);
}

/**
 * reverse_string - reverses a string
 * @str: the string to reverse
 * @length: the length of the string
 */

void reverse_string(char *str, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
