#include "main.h"

/**
 * _islower - Program to check lowercase character
 * @c: integer variable to be check
 * Return: 1 if is lowercase and 0 if is not a lowercase, otherwise
 */

int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}
