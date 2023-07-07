#include "main.h"

/**
 * _isupper - it checks for upper case letters
 * @c: character to check the case
 * Return: 1 if c is upper case and 0 otherwise
 */

int _isupper(int c)
{
if ((c >= 65) && (c <= 90))
{
return (1);
}
else
{
return (0);
}
}
