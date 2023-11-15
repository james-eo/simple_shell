#include "shell.h"

/**
 * my_strncmp - Compare at most 'n' characters of two strings
 * @str1: The first string to compare
 * @str2: The second string to compare
 * @max_chars: The maximum number of characters to compare
 *
 * Return:
 *   0 if the strings are equal,
 *   a negative value if str1 is less than str2,
 *   a positive value if str1 is greater than str2.
 */
int my_strncmp(const char *str1, const char *str2, size_t max_chars)
{
	while (max_chars > 0 && (*str1 != '\0' || *str2 != '\0'))
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
		max_chars--;
	}
	return (0);
}
