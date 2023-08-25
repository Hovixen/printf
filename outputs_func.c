#include "main.h"

/**
 * instance - prints instance buffer
 * @ints: instance buffer pointer
 * @ints_bytes: number of bytes to print for an instance
 * Return: number of bytes printed.
 */
int instance(char *ints, unsigned int ints_bytes)
{
	return (write(1, ints, ints_bytes));
}
/**
 * concat_ints - conbines the instance buffer characters together
 * @ints: instance buffer pointer
 * @c: charcter to concatenate
 * @i_ints: index position of buffer pointer
 * Return: index position of buffer pointer.
 */
unsigned int concat_ints(char *ints, char c, unsigned int i_ints)
{
	if (i_ints == 1024)
	{
		instance(ints, i_ints);
		i_ints = 0;
	}
	ints[i_ints] = c;
	i_ints++;
	return (i_ints);
}

