#include "3-calc.h"

/**
 * op_add - it adds two number.
 * @a: the first number.
 * @b: the second number.
 * Return: result.
 */

int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - it substracts two number.
 * @a: the first number.
 * @b: the second number.
 * Return: result.
 */

int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - it multiplicates two number.
 * @a: the first number.
 * @b: the second number.
 * Return: result.
 */

int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - it divides two number.
 * @a: the first number.
 * @b: the second number.
 * Return: result.
 */

int op_div(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	else
		return (a / b);
}

/**
 * op_mod - it obteins the module between two number.
 * @a: the first number.
 * @b: the second number.
 * Return: result.
 */

int op_mod(int a, int b)
{
	if (b == 0)
	{
		puts("Error");
		exit(100);
	}
	return (a % b);
}
