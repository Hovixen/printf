#include "main.h"
/**
 * _printf - function prints formatted string c, s %.
 * @format: format argument to be given.
 * Return: returns the lenght of string without null.
 */
int _printf(const char *format, ...)
{
	int char_count = 0;/*used to count the number of characters*/
	char c;
	char *str;
	va_list in_args;/*initialize the incoming string arguments*/

	va_start(in_args, format);
	if (format == NULL)
		return (-1);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			char_count++;
		} else /*if *format == '%'*/
		{
			format++;/*go to the next character*/
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c = va_arg(in_args, int);
				write(1, &c, 1);
				char_count++;
			} else if (*format == '%')
			{
				write(1, format, 1);
				char_count++;
			} else if (*format == 's')
			{
				str = va_arg(in_args, char *);
				write(1, str, _strlen(str));
				char_count += _strlen(str);
			} /*else
			{
				write(1, f}*/
		} format++;
	} va_end(in_args);
	return (char_count);
}
