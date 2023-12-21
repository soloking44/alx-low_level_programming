#include "hash_tables.h"

/**
 * key_index - It creates the key using hash_djb2
 * @key: A pointer to the key
 * @size: The size of table
 * Return: An index key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
