#include "main.h"

/**
 * flip_bits - a custom function that calls the number of bits you would
 * need to flip to transform one number to another
 * @n: input number one.
 * @m: input number two.
 *
 * Return: the number of bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int bits_num;

	for (bits_num = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1))
			bits_num++;
	}

	return (bits_num);
}
