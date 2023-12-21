#include "hash_tables.h"

/**
 * hash_djb2 - A hash function that generates djb2
 * @str: A pointer to chars a hash
 * Return: The hash key
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int q;

	while ((q = *str++))
	hash = ((hash << 5) + hash) + q; /* hash * 33 + q */

	return (hash);
}
