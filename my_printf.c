#include "shell.h"

/**
 * my_printf - simplified printf implementation
 * @format: format string
 * @...: variable arguments
 */

void my_printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
