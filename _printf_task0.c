#include "main.h"
/**
 * _printf - function prints formatted string c, s %.
 * @format: format argument to be given.
 * Return: returns the lenght of string without null.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, char_count = 0;/*used to count the number of characters*/
	char c;
	char *str;
	va_list in_args;/*initialize the incoming string arguments*/

	va_start(in_args, format);
	if (format == NULL)
		return (-1);
	while (format && format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			char_count++;
		} else /*if *format == '%'*/
		{
			/*format++;go to the next character*/
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] == 'c')
			{
				c = va_arg(in_args, int);
				write(1, &c, 1);
				char_count++;
			} else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				char_count++;
			} else if (format[i + 1] == 's')
			{
				str = va_arg(in_args, char *);
				if (!str)
					return (-1);
				write(1, str, _strlen(str));
				char_count += _strlen(str);
			}
		} i++;
	} va_end(in_args);
	return (char_count);
}
